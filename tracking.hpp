#include <vector>
#include "object.hpp"
    
namespace Object_types{
namespace Object_tracking{
using memory_model1::ObjectList;

    struct Sensor_measurement{
        std::vector<std::vector<int>> example;
        bool Flag;
    };
    void track_management(ObjectList& Tracklist);
    Sensor_measurement& get_latest_measurement();
    void Process_measurement(ObjectList& Tracklist, Sensor_measurement& measurement); 
    Object_msg generate_output_msg(ObjectList& Tracklist);
} //Object_types
} //Object_tracking
