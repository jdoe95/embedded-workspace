/*
 * Doubly Linked Queue
 * Dynamic queue with unlimited capacity.
 */
#include <utility/linkq.h>
#include <platform/contend.h>
#include <stddef.h>



/*
 * Initializes a linked queue instance
 */
void lq_init(struct lq_inst *inst)
{
	CONTEND(inst != NULL);

	inst->head = NULL;
}



/*
 * Initializes a linked queue item
 * The lq_item::container pointer may be initialized before or after.
 */
void lq_item_init(struct lq_item *item)
{
	CONTEND(item != NULL);

	item->prev = item;
	item->next = item;
}



/*
 * Inserts an item before the indicated position.
 * The function does not update the queue head.
 */
void lq_pre_ins(struct lq_item *pos, struct lq_item *item)
{
	CONTEND(pos != NULL);
	CONTEND(item != NULL);

	/*
	 * If these fail, the item is either uninitialized or already enslaved by another queue.
	 */
	CONTEND(item->prev == item);
	CONTEND(item->next == item);

	/*
	 * If these fail, the position item is corrupted
	 */
	CONTEND(pos->prev != NULL);
	CONTEND(pos->next != NULL);

	item->next = pos;
	item->prev = pos->prev;

	item->next->prev = item;
	item->prev->next = item;
}



/*
 * Inserts an item after the indicated position.
 * The function does not update the queue head.
 */
void lq_post_ins(struct lq_item *pos, struct lq_item *item)
{
	CONTEND(pos != NULL);
	CONTEND(item != NULL);

	/*
	 * If these fail, the item is either uninitialized or already enslaved by another queue.
	 */
	CONTEND(item->prev == item);
	CONTEND(item->next == item);

	/*
	 * If these fail, the position item is corrupted
	 */
	CONTEND(pos->prev != NULL);
	CONTEND(pos->next != NULL);

	item->prev = pos;
	item->next = pos->next;

	item->next->prev = item;
	item->prev->next = item;
}



/*
 * Removes an item from the queue
 * The queue head is set to NULL if removing the last item, set to the next item if removing the
 * head, and unchanged otherwise.
 */
void lq_rm(struct lq_inst *inst, struct lq_item *item)
{
	CONTEND(inst != NULL);
	CONTEND(item != NULL);

	/*
	 * Attempting to remove from an empty queue.
	 */
	CONTEND(inst->head != NULL);

	/*
	 * If these fail, the item is corrupted.
	 */
	CONTEND(item->prev != NULL);
	CONTEND(item->next != NULL);

	/* removing head */
	if (inst->head == item)
	{
		/* the queue has only 1 item */
		if (inst->head == inst->head->next)
		{
			/*
			 * If this fails, the arms of the queue item are inconsistent, suggesting corruption.
			 */
			CONTEND(inst->head == inst->head->prev);

			inst->head = NULL;
		}

		else
			inst->head = inst->head->next;
	}

	item->prev->next = item->next;
	item->next->prev = item->prev;
	item->prev = item;
	item->next = item;
}



/*
 * Pushes an item onto the tail of the queue.
 * The function sets queue head if and only if it's NULL.
 */
void lq_push_tail(struct lq_inst *inst, struct lq_item *item)
{
	CONTEND(inst != NULL);
	CONTEND(item != NULL);

	/*
	 * If these fail, the queue item is either uninitialized or already enslaved by another queue.
	 */
	CONTEND(item->prev == item);
	CONTEND(item->next == item);

	if (inst->head == NULL)
		inst->head = item;

	else
		lq_pre_ins(inst->head, item);
}



/*
 * Pops an item from the head of the queue.
 * The function always updates the queue head. NULL will be returned if the queue is empty.
 */
struct lq_item* lq_pop_head(struct lq_inst *inst)
{
	CONTEND(inst != NULL);

	struct lq_item *head = inst->head;

	if (head == NULL)
	{
		/* intentionally left blank */
	}

	else
		lq_rm(inst, head);

	return head;
}
