#include "iter.cpp"
 
Television::Television(){}
 
Television::Television(const vector<string>& iChannelList){
	this->channelList = iChannelList;
}
 
Iterator* Television::createIterator(){
    return new RemoteControl(this);
}
 
int Television::getTotalChannelNum(){
	return channelList.size();
}
 
void Television::play(int i){
    cout <<"现在频道：" << channelList[i] << endl;
}