/*
 * Doubly Linked Queue Unit Tests
 */
#include <utility/linkq.h>
#include <testing/death-string.h>
#include <googletest/gtest.h>
#include <vector>



TEST(LinkQ, ParamDeath) {
	EXPECT_DEATH(lq_init(nullptr), TESTING_DEATH_STRING);
	EXPECT_DEATH(lq_item_init(nullptr), TESTING_DEATH_STRING);

	struct lq_item dummy_item;

	EXPECT_DEATH(lq_pre_ins(nullptr, nullptr), TESTING_DEATH_STRING);
	EXPECT_DEATH(lq_pre_ins(&dummy_item, nullptr), TESTING_DEATH_STRING);
	EXPECT_DEATH(lq_pre_ins(nullptr, &dummy_item), TESTING_DEATH_STRING);

	EXPECT_DEATH(lq_post_ins(nullptr, nullptr), TESTING_DEATH_STRING);
	EXPECT_DEATH(lq_post_ins(&dummy_item, nullptr), TESTING_DEATH_STRING);
	EXPECT_DEATH(lq_post_ins(nullptr, &dummy_item), TESTING_DEATH_STRING);

	struct lq_inst dummy_inst;

	EXPECT_DEATH(lq_rm(nullptr, nullptr), TESTING_DEATH_STRING);
	EXPECT_DEATH(lq_rm(nullptr, &dummy_item), TESTING_DEATH_STRING);
	EXPECT_DEATH(lq_rm(&dummy_inst, nullptr), TESTING_DEATH_STRING);

	EXPECT_DEATH(lq_push_tail(nullptr, nullptr), TESTING_DEATH_STRING);
	EXPECT_DEATH(lq_push_tail(nullptr, &dummy_item), TESTING_DEATH_STRING);
	EXPECT_DEATH(lq_push_tail(&dummy_inst, nullptr), TESTING_DEATH_STRING);

	EXPECT_DEATH(lq_pop_head(nullptr), TESTING_DEATH_STRING);
}


/*
 * Tests that insertion of an uninitialized queue item causes death
 */
TEST(LinkQ, InsUninitDeath) {
	struct lq_item good_item;
	lq_item_init(&good_item);

	struct lq_item bad_item;
	struct lq_item dummy1;
	struct lq_item dummy2;

	bad_item.prev = &dummy1;
	bad_item.next = &dummy2;

	EXPECT_DEATH(lq_pre_ins(&bad_item, &bad_item), TESTING_DEATH_STRING);
	EXPECT_DEATH(lq_pre_ins(&good_item, &bad_item), TESTING_DEATH_STRING);

	EXPECT_DEATH(lq_post_ins(&bad_item, &bad_item), TESTING_DEATH_STRING);
	EXPECT_DEATH(lq_post_ins(&good_item, &bad_item), TESTING_DEATH_STRING);

	struct lq_inst dummy_inst;
	lq_init(&dummy_inst);

	EXPECT_DEATH(lq_push_tail(&dummy_inst, &bad_item), TESTING_DEATH_STRING);
}



/*
 * Tests that removal of items from an empty queue causes death
 */
TEST(LinkQ, RmEmptyDeath) {
	struct lq_inst inst;
	lq_init(&inst);

	struct lq_item dummy_item;
	lq_item_init(&dummy_item);

	EXPECT_DEATH(lq_rm(&inst, &dummy_item), TESTING_DEATH_STRING);
}



/*
 * Provides a test fixture to check the linked list
 */
struct LinkQTest: public testing::Test {
public:
	struct lq_inst m_inst;

	using ResultType = std::vector<const struct lq_item*>;

	/* parameter is modified so does not pass by reference */
	void verifyResult(ResultType expected) {

		const struct lq_item *actual_item = m_inst.head;

		/* checking head twice allows full traversal of the results */
		expected.push_back(expected.front());

		for (const struct lq_item *expected_item : expected) {

			EXPECT_EQ(actual_item, expected_item);

			/* also checks integrity of links */
			EXPECT_EQ(actual_item->prev->next, actual_item);
			EXPECT_EQ(actual_item->next->prev, actual_item);

			actual_item = actual_item->next;
		}
	}
};



TEST_F(LinkQTest, PushTail) {
	struct lq_item items[5];

	lq_init(&m_inst);

	ResultType expected;

	for (struct lq_item& item : items) {
		lq_item_init(&item);

		lq_push_tail(&m_inst, &item);

		expected.push_back(&item);
	}

	verifyResult(expected);
}



TEST_F(LinkQTest, PushTailPopHead) {
	struct lq_item items[5];

	lq_init(&m_inst);

	for (struct lq_item& item : items) {
		lq_item_init(&item);
		lq_push_tail(&m_inst, &item);
	}

	/* pops 3 items */
	for (size_t counter = 0; counter < 3; ++counter) {
		lq_pop_head(&m_inst);
	}

	verifyResult(ResultType({
		&items[3],
		&items[4]
	}));
}



TEST_F(LinkQTest, PostIns) {
	struct lq_item head;
	struct lq_item items[5];

	lq_init(&m_inst);

	lq_item_init(&head);
	lq_push_tail(&m_inst, &head);

	for (struct lq_item& item : items) {
		lq_item_init(&item);
		lq_post_ins(&head, &item);
	}

	verifyResult(ResultType({
		&head,
		&items[4],
		&items[3],
		&items[2],
		&items[1],
		&items[0]
	}));
}



TEST_F(LinkQTest, PreIns) {
	struct lq_item head;
	struct lq_item items[5];

	lq_init(&m_inst);

	lq_item_init(&head);
	lq_push_tail(&m_inst, &head);

	for (struct lq_item& item : items) {
		lq_item_init(&item);
		lq_pre_ins(&head, &item);
	}

	verifyResult(ResultType({
		&head,
		&items[0],
		&items[1],
		&items[2],
		&items[3],
		&items[4]
	}));
}


TEST_F(LinkQTest, ComplexInsRm) {
	struct lq_item head;
	struct lq_item items[5];

	lq_init(&m_inst);

	lq_item_init(&head);
	lq_push_tail(&m_inst, &head);

	for (struct lq_item& item : items)
		lq_item_init(&item);

	lq_pre_ins(&head, &items[0]);
	lq_rm(&m_inst, &head);
	lq_pop_head(&m_inst);
	lq_pop_head(&m_inst);
	lq_pop_head(&m_inst);
	lq_pop_head(&m_inst);

	lq_push_tail(&m_inst, &items[0]);
	lq_pre_ins(&items[0], &items[1]);
	lq_pre_ins(&items[0], &items[2]);
	lq_post_ins(&items[0], &items[3]);
	lq_post_ins(&items[0], &items[4]);

	verifyResult(ResultType({
		&items[0],
		&items[4],
		&items[3],
		&items[1],
		&items[2],
	}));

}
