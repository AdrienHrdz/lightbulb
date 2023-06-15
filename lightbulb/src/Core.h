#pragma once

#include <iostream>

#ifdef LB_DEBUG
	#define LB_LOG_INFO(message)    std::cout << "[INFO] : " << message << std::endl
	#define LB_LOG_WARN(message)    std::cout << "[WARNING] : " << message << std::endl
	#define LB_LOG_ERROR(message)   std::cout << "[ERROR] : " << message << std::endl

	#define LB_ASSERT(condition, message) if(!condition) { std::cout << message << std::endl; __debugbreak(); }
#else
	#define LB_LOG_INFO(message)
	#define LB_LOG_WARN(message)
	#define LB_LOG_ERROR(message)

	#define LB_ASSERT(condition, message)
#endif