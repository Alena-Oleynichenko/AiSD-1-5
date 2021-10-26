#include "pch.h"
#include <iostream>
#include <time.h>
#include <cstdio>
#include "..//Project175/Header.h"

TEST(image, setIndex)
{
	image M(1, 2);
	M.SetMij(0, 0, 1);
	M.SetMij(0, 1, 0); 
	EXPECT_EQ(1, M.GetMij(0,0));
	EXPECT_EQ(0, M.GetMij(0, 1));

}
TEST(image, Constr)
{
	//image M(-1, 1);
	//EXPECT_EQ(, M.GetMij(0, 0));
	EXPECT_THROW(image M(-1,1), const char*);
}
TEST(image, Canmulti)
{
	image test1(2, 2), test2(2, 2), test3(3, 2);
	EXPECT_EQ(1, test1.can_multiply(test2));
	EXPECT_EQ(0, test1.can_multiply(test3));
}
TEST(image, Sum)
{
	image test1(2,2), test2(2,2);
	test1.SetMij(1, 1,0);
	test1.SetMij(0, 1,1);
	test1.SetMij(1,0, 1);
	test1.SetMij(1, 1, 0);
	image test3 = test1 + test2;
	EXPECT_EQ(test3.GetMij(1, 0), 1);
	EXPECT_EQ(test3.GetMij(0, 1), 1);
}
TEST(image, Mult)
{
	image test1(2, 2), test2(2, 2);
	test1.SetMij(1, 1, 0);
	test1.SetMij(0, 1, 0);
	test1.SetMij(1, 0, 1);
	test1.SetMij(0, 0, 1);
	test2.SetMij(0, 0, 1);
	test2.SetMij(1, 0, 1);
	test2.SetMij(1, 1, 1);
	test2.SetMij(0, 1, 1);
	image test3 = test1 * test2;
	EXPECT_EQ(test3.GetMij(0, 1), 0);
	EXPECT_EQ(test3.GetMij(1, 0), 1);
	EXPECT_EQ(test3.GetMij(1, 1), 0);
}
TEST(image, Equal)
{
	image test1(2, 2);
	test1.SetMij(1, 1, 1);
	test1.SetMij(0, 1, 0);
	test1.SetMij(1, 0, 1);
	test1.SetMij(0, 0, 0);
	image test2 = test1;
	EXPECT_EQ(test2.GetMij(1, 1), 1);
	EXPECT_EQ(test2.GetMij(1, 0), 1);
}
TEST(image, invers)
{
	image test1(2, 2);
	test1.SetMij(1, 1, 1);
	test1.SetMij(0, 1, 0);
	test1.SetMij(1, 0, 1);
	test1.SetMij(0, 0, 1);
	(!test1);
	EXPECT_EQ(test1.GetMij(1, 1), 1);
	EXPECT_EQ(test1.GetMij(0, 0), 1);
	EXPECT_EQ(test1.GetMij(0, 1), 0);
	EXPECT_EQ(test1.GetMij(1, 0), 1);
}

TEST(image, fill)
{
	image test(2, 2);
	test.SetMij(1, 1, 1);
	test.SetMij(0, 1, 0);
	test.SetMij(1, 0, 1);
	test.SetMij(0, 0, 1);
	double c = 0.75;	
	EXPECT_EQ(test.coefficient(), c);
}
TEST(image, Vvod)
{
	image test1(2, 2);
	image test2;
	EXPECT_EQ(true, test1.draw() );
	EXPECT_EQ(false, test2.draw());
}