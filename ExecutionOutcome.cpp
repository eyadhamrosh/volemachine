#include <iostream>
#include "ExecutionOutcome.h"

std::string toString(ExecutionOutcome outcome)
{

    
    switch (outcome)
    {
        case ExecutionOutcome::CONTINUE:
            return "CONTINUE";

        case ExecutionOutcome::JUMPED:
            return "JUMPED";

        case ExecutionOutcome::HALT:
            return "HALT";
    }

    return "UNKNOWN";
}