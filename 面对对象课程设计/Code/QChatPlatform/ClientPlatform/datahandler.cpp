#include "datahandler.h"

DataHandler::DataHandler()
{

}

DataHandler *DataHandler::GetInstance()
{
    static DataHandler instance;
    return &instance;
}
