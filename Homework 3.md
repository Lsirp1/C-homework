Homework 3:



**6. What is the difference between the \* and \& operators?**



The \* operator is a pointer to a variable and can access the variables value when dereferencing. The \& operator is the variables address.



**9. Describe what each of the following declare:**

**int\* a;** --> an integer pointer a

**const int b;** --> a constant integer b

**const int\* c;** --> a pointer c to a constant integer

**int\* const d;** --> a constant pointer d to an integer

**const int\* const e;** --> a constant pointer e to a constant integer



**12. This code computes both the square and cube of a number. What is wrong with it and how would you fix it?**

**double\* powers(double x, double\* x3\_ptr){**



	**double x2 = x\*x;**

	**\*x3\_ptr = x2\*x;**

	**return \&x2;**

**}**



x2 only exists within this function and its address will be forgotten after the function completes. You can fix it by simply returning x2.



**13. Sometimes when you call this function, you get a seg fault. In what line is the seg fault occurring?**

**void twitchy(int n, int\* out){**

	

	**int sum = 0;**

	**for(int i = 0; i<n; ++i){**

		**if(i%2) sum += 5;**

		**else sum/=2;**

	**}**

	

	**\*out = sum;**

**}**



If out is either null or not properly initialized.

