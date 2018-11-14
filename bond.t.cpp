#include <bond.h>
#include <gtest/gtest.h>

/*	-------
	GETTERS:
	-------
*/

TEST(getName, DefaultInput) {
	Bond newBond1("newBond1", 1000.0, 0.053, 10);
	Bond newBond2("newBond2", 500.5, 0.042, 12);
	Bond newBond3("", 500.5, 0.042, 12);

	EXPECT_EQ("newBond1", newBond1.getName());
	EXPECT_EQ("newBond2", newBond2.getName());
	EXPECT_EQ("", newBond2.getName());
}

TEST(getParValue, PositiveInput) {
	Bond newBond1("newBond1", 1000.0, 0.053, 10);
	Bond newBond2("newBond2", 500.5, 0.042, 12);

	EXPECT_DOUBLE_EQ(1000, newBond1.getParValue());
	EXPECT_DOUBLE_EQ(500.5, newBond2.getParValue());
}

TEST(getInterestRate, PositiveInput) {
	Bond newBond1("newBond1", 1000.0, 0.053, 10);
	Bond newBond2("newBond2", 500.5, 0.042, 12);
	Bond newBond3("newBond3", 500.5, 0, 12);

	EXPECT_DOUBLE_EQ(0.053, newBond1.getInterestRate());
	EXPECT_DOUBLE_EQ(0.042, newBond2.getInterestRate());
	EXPECT_DOUBLE_EQ(0, newBond3.getInterestRate());
}

TEST(getInterestRate, NegativeInput) {
	Bond newBond1("newBond1", 1000.0, -0.053, 10);
	Bond newBond2("newBond2", 500.5, -0.042, 12);

	EXPECT_DOUBLE_EQ(-0.053, newBond1.getInterestRate());
	EXPECT_DOUBLE_EQ(-0.042, newBond2.getInterestRate());
}

TEST(getYearsToMaturity, PositiveInput) {
	Bond newBond1("newBond1", 1000.0, 0.053, 10);
	Bond newBond2("newBond2", 500.5, 0.042, 12);
	Bond newBond3("newBond3", 500.5, 0.042, 0);

	EXPECT_DOUBLE_EQ(10, newBond1.getYearsToMaturity());
	EXPECT_DOUBLE_EQ(12, newBond2.getYearsToMaturity());
	EXPECT_DOUBLE_EQ(0, newBond3.getYearsToMaturity());
}

TEST(getYearsToMaturity, NegativeInput) {
	Bond newBond1("newBond1", 1000.0, 0.053, -10);
	Bond newBond2("newBond2", 500.5, 0.042, -12);

	EXPECT_DOUBLE_EQ(-10, newBond1.getYearsToMaturity());
	EXPECT_DOUBLE_EQ(-12, newBond2.getYearsToMaturity());
}

/*	-------
	SETTERS:
	-------
*/

TEST(setName, DefaultInput) {
	Bond newBond1("newBond1", 1000.0, 0.053, 10);
	Bond newBond2("newBond2", 500.5, 0.042, 12);
	Bond newBond3("", 500.5, 0.042, 12);

	newBond1.setName("testBond1");
	newBond2.setName("");
	newBond3.setName("testBond3");

	EXPECT_EQ("testBond1", newBond1.getName());
	EXPECT_EQ("", newBond2.getName());
	EXPECT_EQ("testBond1", newBond2.getName());
}

TEST(setParValue, PositiveInput) {
	Bond newBond1("newBond1", -1000.0, 0.053, 10);
	Bond newBond2("newBond2", 500.5, 0.042, 12);
	Bond newBond3("newBond3", 1000, 0.042, 12);

	newBond1.setParValue(1000.5);
	newBond2.setParValue(150);

	EXPECT_DOUBLE_EQ(1000.5, newBond1.getParValue());
	EXPECT_DOUBLE_EQ(150, newBond2.getParValue());
}

TEST(setInterestRate, PositiveInput) {
	Bond newBond1("newBond1", 1000.0, 0.053, 10);
	Bond newBond2("newBond2", 500.5, -0.042, 12);
	Bond newBond3("newBond3", 500.5, 0.4, 12);

	newBond1.setInterestRate(0.05);
	newBond2.setInterestRate(0.04);
	newBond3.setInterestRate(0);

	EXPECT_DOUBLE_EQ(0.05, newBond1.getInterestRate());
	EXPECT_DOUBLE_EQ(0.04, newBond2.getInterestRate());
	EXPECT_DOUBLE_EQ(0, newBond3.getInterestRate());
}

TEST(setInterestRate, NegativeInput) {
	Bond newBond1("newBond1", 1000.0, 0.053, 10);
	Bond newBond2("newBond2", 500.5, -0.042, 12);

	newBond1.setInterestRate(-0.05);
	newBond2.setInterestRate(-0.04);

	EXPECT_DOUBLE_EQ(-0.05, newBond1.getInterestRate());
	EXPECT_DOUBLE_EQ(-0.04, newBond2.getInterestRate());
}

TEST(setYearsToMaturity, PositiveInput) {
	Bond newBond1("newBond1", 1000.0, 0.053, 10);
	Bond newBond2("newBond2", 500.5, 0.042, -12);
	Bond newBond3("newBond3", 500.5, 0.042, 100);

	newBond1.setYearsToMaturity(50);
	newBond2.setYearsToMaturity(25);
	newBond3.setYearsToMaturity(0);

	EXPECT_DOUBLE_EQ(50, newBond1.getYearsToMaturity());
	EXPECT_DOUBLE_EQ(25, newBond2.getYearsToMaturity());
	EXPECT_DOUBLE_EQ(0, newBond3.getYearsToMaturity());
}

TEST(setYearsToMaturity, NegativeInput) {
	Bond newBond1("newBond1", 1000.0, 0.053, 10);
	Bond newBond2("newBond2", 500.5, 0.042, -12);

	newBond1.setYearsToMaturity(-50);
	newBond2.setYearsToMaturity(-25);

	EXPECT_DOUBLE_EQ(50, newBond1.getYearsToMaturity());
	EXPECT_DOUBLE_EQ(25, newBond2.getYearsToMaturity());
}

/*	-------
	METHODS:
	-------
*/

TEST(calculateCurrentYield, PositiveInput){
	Bond newBond1("newBond1", 1000.0, 0.053, 10);
	Bond newBond2("newBond2", 500.5, 0.042, 12);
	Bond newBond3("newBond3", 0, 0.053, 10);
	Bond newBond4("newBond4", 1000.0, 0, 10);

    EXPECT_DOUBLE_EQ(0.059, newBond1.calculateCurrentYield(1000, 0.053, 900));
	EXPECT_DOUBLE_EQ(0.059, newBond1.calculateCurrentYield(900));

	EXPECT_DOUBLE_EQ(0.02627625, newBond2.calculateCurrentYield(500.5, 0.042, 800));
	EXPECT_DOUBLE_EQ(0.02627625, newBond2.calculateCurrentYield(800));

	EXPECT_DOUBLE_EQ(0, newBond3.calculateCurrentYield(0, 0.053, 900));
	EXPECT_DOUBLE_EQ(0, newBond3.calculateCurrentYield(900));

	EXPECT_DOUBLE_EQ(0, newBond4.calculateCurrentYield(1000, 0, 900));
	EXPECT_DOUBLE_EQ(0, newBond4.calculateCurrentYield(900));
}

TEST(calculateCurrentYield, NegativeInput) {
	Bond newBond1("newBond1", 1000.0, -0.053, 10);
	Bond newBond2("newBond2", 500.5, 0.042, -12);
	Bond newBond3("newBond3", 0, -0.053, 10);
	Bond newBond4("newBond4", 1000.0, 0, -10);

	EXPECT_DOUBLE_EQ(-0.059, newBond1.calculateCurrentYield(1000, -0.053, 900));
	EXPECT_DOUBLE_EQ(-0.059, newBond1.calculateCurrentYield(900));

	EXPECT_DOUBLE_EQ(0.02627625, newBond2.calculateCurrentYield(500.5, 0.042, 800));
	EXPECT_DOUBLE_EQ(0.02627625, newBond2.calculateCurrentYield(800));

	EXPECT_DOUBLE_EQ(0, newBond3.calculateCurrentYield(0, 0.053, 900));
	EXPECT_DOUBLE_EQ(0, newBond3.calculateCurrentYield(900));

	EXPECT_DOUBLE_EQ(0, newBond4.calculateCurrentYield(1000, 0, 900));
	EXPECT_DOUBLE_EQ(0, newBond4.calculateCurrentYield(900));
}
