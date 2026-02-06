#include<iostream>
using namespace std;
class Device{
    protected:
    int deviceID;
    public:
    Device(int id){
        deviceID=id;
    }
    void showID(){
        cout<<"Device ID is "<<deviceID<<endl;
    }
};
class Internet{
    protected:
    string ipAddress;
    public:
    Internet(string ip){
        ipAddress=ip;
    }
    void showIP(){
        cout<<"Internt IP is "<<ipAddress<<endl;
    }
};
class SmartCamera : public Device , public Internet{
    private :
    int *videoData;
    int recordingSize;
    public:
    SmartCamera (int id, string ip,int size):Device(id),Internet(ip),recordingSize(size){
         videoData = new int[size];
        for(int i = 0; i < size; i++) {
            videoData[i] = i; 
        }
        cout << "SmartCamera created with recording size " << recordingSize << endl;
    }
    SmartCamera(const SmartCamera &obj):Device(obj), Internet(obj),recordingSize(obj.recordingSize){
        videoData = new int[recordingSize];
        for(int i = 0; i < recordingSize; i++) {
            videoData[i] = obj.videoData[i];
        }
        cout << "SmartCamera copied (Deep Copy)\n";
    }
    ~SmartCamera(){
        delete[] videoData;
        cout<<"Memory free\n";
    }
     void setVideoFrame(int index, int value) {
        if (index >= 0 && index < recordingSize)
            videoData[index] = value;
    }

    
    void showVideoFrame(int index) {
        if (index >= 0 && index < recordingSize)
            cout << videoData[index] << endl;
    }

};
int main() {
    cout << "--- Creating Camera 1 ---" << endl;
    
    SmartCamera cam1(101, "192.168.1.1", 5);
    
    cout << "\n--- Creating Camera 2 (Copy of Cam 1) ---" << endl;
    SmartCamera cam2 = cam1; 

    cout << "\n--- Modifying Camera 1 Data ---" << endl;
    
    cam1.setVideoFrame(0, 999); 

    cout << "\n--- Checking Data ---" << endl;
    cout << "Cam 1 Frame 0: "; 
    cam1.showVideoFrame(0); 

    cout << "Cam 2 Frame 0: "; 
    cam2.showVideoFrame(0);.

    return 0;
}