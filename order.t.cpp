#include <order.h>
#include <gtest/gtest.h>

/*	-------
	GETTERS:
	-------
*/

TEST(getName, DefaultInput) {
	Order newOrder1("buyer1", 1000, 123.45, 10000);
	Order newOrder2("buyer2", 1400, 74.47, 12000);
	Order newOrder3("", 1400, 74.47, 12000);

	EXPECT_EQ("buyer1", newOrder1.getBuyerName());
	EXPECT_EQ("buyer2", newOrder2.getBuyerName());
	EXPECT_EQ("", newOrder3.getBuyerName());
}

TEST(getSize, PositiveInput) {
	Order newOrder1("buyer1", 1000, 123.45, 10000);
	Order newOrder2("buyer2", 1400, 74.47, 12000);
	Order newOrder3("buyer3", 0, 74.47, 12000);

	EXPECT_DOUBLE_EQ(1000, newOrder1.getSize());
	EXPECT_DOUBLE_EQ(1400, newOrder2.getSize());
	EXPECT_DOUBLE_EQ(0, newOrder3.getSize());
}

TEST(getMaxPrice, PositiveInput) {
	Order newOrder1("buyer1", 1000, 123.45, 10000);
	Order newOrder2("buyer2", 1400, 74.47, 12000);
	Order newOrder3("buyer3", 1400, 0, 12000);

	EXPECT_DOUBLE_EQ(123.45, newOrder1.getMaxPrice());
	EXPECT_DOUBLE_EQ(74.47, newOrder2.getMaxPrice());
	EXPECT_DOUBLE_EQ(0, newOrder3.getMaxPrice());
}

TEST(getOrderTime, PositiveInput) {
	Order newOrder1("buyer1", 1000, 123.45, 10000);
	Order newOrder2("buyer2", 1400, 74.47, 12000);
	Order newOrder3("buyer3", 1400, 74.47, 0);

	EXPECT_DOUBLE_EQ(10000, newOrder1.getOrderTime());
	EXPECT_DOUBLE_EQ(12000, newOrder2.getOrderTime());
	EXPECT_DOUBLE_EQ(0, newOrder3.getOrderTime());
}

/*	-------
	SETTERS:
	-------
*/

TEST(setName, DefaultInput) {
	Order newOrder1("buyer1", 1000, 123.45, 10000);
	Order newOrder2("buyer2", 1400, 74.47, 12000);
	Order newOrder3("buyer3", 1400, 74.47, 0);

	newOrder1.setBuyerName("setBuyer1");
	newOrder2.setBuyerName("");
	newOrder3.setBuyerName("setBuyer3");

	EXPECT_EQ("setBuyer1", newOrder1.getBuyerName());
	EXPECT_EQ("", newOrder2.getBuyerName());
	EXPECT_EQ("setBuyer3", newOrder3.getBuyerName());
}

TEST(setSize, PositiveInput) {
	Order newOrder1("buyer1", 1000, 123.45, 10000);
	Order newOrder2("buyer2", -1400, 74.47, 12000);
	Order newOrder3("buyer3", 1400, 74.47, 0);

	newOrder1.setSize(0);
	newOrder2.setSize(700);
	newOrder3.setSize(900);

	EXPECT_EQ(0, newOrder1.getSize());
	EXPECT_EQ(700, newOrder2.getSize());
	EXPECT_EQ(900, newOrder3.getSize());
}

TEST(setMaxPrice, PositiveInput) {
	Order newOrder1("buyer1", 1000, 123.45, 10000);
	Order newOrder2("buyer2", 1400, -74.47, 12000);
	Order newOrder3("buyer3", 1400, 74.47, 0);

	newOrder1.setMaxPrice(0);
	newOrder2.setMaxPrice(12.09);
	newOrder3.setMaxPrice(567.89);

	EXPECT_EQ(0, newOrder1.getMaxPrice());
	EXPECT_EQ(12.09, newOrder2.getMaxPrice());
	EXPECT_EQ(567.89, newOrder3.getMaxPrice());
}

TEST(setOrderTime, PositiveInput) {
	Order newOrder1("buyer1", 1000, 123.45, 10000);
	Order newOrder2("buyer2", 1400, 74.47, -12000);
	Order newOrder3("buyer3", 1400, 74.47, 0);

	newOrder1.setOrderTime(30000);
	newOrder2.setOrderTime(0);
	newOrder3.setOrderTime(32000);

	EXPECT_EQ(30000, newOrder1.getOrderTime());
	EXPECT_EQ(0, newOrder2.getOrderTime());
	EXPECT_EQ(32000, newOrder3.getOrderTime());
}

/*	-------
	METHODS:
	-------
*/

