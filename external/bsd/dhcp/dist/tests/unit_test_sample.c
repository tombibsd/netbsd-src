/*	$NetBSD$	*/
#include "config.h"
#include "t_api.h"

static void foo(void);

/*
 * T_testlist is a list of tests that are invoked.
 */
testspec_t T_testlist[] = {
	{	foo,		"sample test" 	},
	{	NULL,		NULL 		}
};

static void
foo(void) {
	static const char *test_desc = 
		"this is an example test, for no actual module";

	t_assert("sample", 1, T_REQUIRED, test_desc);

	/* ... */	/* Test code would go here. */

	t_result(T_PASS);
}

