#include <assert.h> 
 #include<vector> 
template <class T> class compcxx_array { public: 
virtual ~compcxx_array() { for (typename std::vector<T*>::iterator i=m_elements.begin();i!=m_elements.end();i++) delete (*i); } 
void SetSize(unsigned int n) { for(unsigned int i=0;i<n;i++)m_elements.push_back(new T); } 
T& operator [] (unsigned int i) { assert(i<m_elements.size()); return(*m_elements[i]); } 
unsigned int size() { return m_elements.size();} 
private: std::vector<T*> m_elements; }; 
class compcxx_component; 
template <class T> class compcxx_functor {public: 
void Connect(compcxx_component&_c, T _f){ c.push_back(&_c); f.push_back(_f); } 
protected: std::vector<compcxx_component*>c; std::vector<T> f; }; 
class compcxx_component { public: 
typedef void  (compcxx_component::*AP_outSetNeighbors_f_t)(APBeacon &b);
typedef void  (compcxx_component::*AP_outSendBeaconToNodes_f_t)(APBeacon &b);
typedef void  (compcxx_component::*AP_outAssignAirTime_f_t)(Connection &n);
typedef void  (compcxx_component::*AP_outLoadToNeighbor_f_t)(ApNotification &ap);
typedef void  (compcxx_component::*AP_outChannelChange_f_t)(APBeacon &b);
typedef void  (compcxx_component::*Station_outSetClientAssociation_f_t)(StationInfo &i);
typedef void  (compcxx_component::*Station_outRequestAirTime_f_t)(Connection &n);
typedef void  (compcxx_component::*Station_outFlowEnded_f_t)(Connection &n);
typedef void  (compcxx_component::*Station_outUpdateAttachedStationsParams_f_t)(StationInfo &i);
typedef void  (compcxx_component::*Station_outUpdateConnection_f_t)(StationInfo &i, int k);
};
