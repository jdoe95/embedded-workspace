/***************************************************************************************************
 * Doubly Linked Queue
 * Dynamic queue with unlimited capacity.
 *
 * Items are linked into a ring so that there are no boundary conditions when traversing the queue.
 * Items can be removed and inserted with constant O(1) time complexity. The queue does not handle
 * the allocation and deallocation of items. An item shall be enslaved by no more than 1 queue.
 **************************************************************************************************/
#ifndef HCA6B0EE7_FD75_44B5_A43D_940091CD32C6
#define HCA6B0EE7_FD75_44B5_A43D_940091CD32C6



/*
 * Queue Item
 */
struct lq_item
{
	/* PRIVATE MEMBERS */
	struct lq_item *next;  /* points to the next peer */
	struct lq_item *prev;  /* points to the previous peer */

	/* PUBLIC MEMBERS */
	void *payload;         /* payload data */
};



/*
 * Queue Instance
 * ALL MEMBERS ARE PRIVATE
 */
struct lq_inst
{
	struct lq_item *head;  /* the logical head of the ring */
};



#if defined(__cplusplus)
extern "C" {
#endif

/*
 * Initializes a linked queue instance
 */
void lq_init(struct lq_inst *inst);

/*
 * Initializes a linked queue item
 * The lq_item::container pointer may be initialized before or after.
 */
void lq_item_init(struct lq_item *item);

/*
 * Inserts an item before the indicated position.
 * The function does not update the queue head.
 */
void lq_pre_ins(struct lq_item *pos, struct lq_item *item);

/*
 * Inserts an item after the indicated position.
 * The function does not update the queue head.
 */
void lq_post_ins(struct lq_item *pos, struct lq_item *item);

/*
 * Removes an item from the queue
 * The queue head is set to NULL if removing the last item, set to the next item if removing the
 * head, and unchanged otherwise.
 */
void lq_rm(struct lq_inst *inst, struct lq_item *item);

/*
 * Pushes an item onto the tail of the queue.
 * The function sets queue head if and only if it's NULL.
 */
void lq_push_tail(struct lq_inst *inst, struct lq_item *item);

/*
 * Pops an item from the head of the queue.
 * The function always updates the queue head. NULL will be returned if the queue is empty.
 */
struct lq_item* lq_pop_head(struct lq_inst *inst);

#if defined(__cplusplus)
}
#endif

#endif /* HCA6B0EE7_FD75_44B5_A43D_940091CD32C6 */
