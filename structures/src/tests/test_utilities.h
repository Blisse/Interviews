#ifndef _TEST_UTILITIES_H__
#define _TEST_UTILITIES_H__

#include "common.h"

#define TRUE(hr) ((int)(hr) == 1)
#define FALSE(hr) ((int)(hr) == 0)
#define RETURN_IF_FALSE(hr) { if(FALSE(hr)) { return; } }
#define RETURN_ERROR_IF_FALSE(hr) { if(FALSE(hr)) { return ERROR; } }


#define SUCCEEDED(hr) ((int)(hr) == SUCCESS)
#define FAILED(hr) ((int)(hr) != SUCCESS)
#define RETURN_ERROR_IF_FAILED(hr) { if(FAILED(hr)) { return ERROR; } }

#endif
