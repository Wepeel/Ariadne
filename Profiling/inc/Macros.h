#pragma once
#include "Timer.h"

#define ARD_PROFILE_SCOPE(name) timer time(name)

#define ARD_PROFILE_FUNCTION() ARD_PROFILE_SCOPE(__FUNCSIG__)