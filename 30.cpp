#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>
using namespace std;

class test{
    public:
    vector<int> sss;
    int testint;
    test(int n, int s){
        sss = vector<int>(n);
        testint = s;
    }
};

int main(){
    unordered_map <string,int> map;
    unordered_map <string,int> map2;
    vector<string> str = {"a","a","abc","abcd"};
    for(string a : str){
        cout << map[a] << endl;
        map[a] = map[a] + 1;//map[a]是你key对应的value。 a才是你的key。所以这里的意思是 你map[a]的这个val+1。你map的key是map.first
        //如果map[a]有这个key 比如里面有a 那么这个val+1
        //如果map[a] 没有这个key。那就加这个key 比如里面没有abc 那就把abc加进去
        //map[num];对于这个下标操作，如果存在num关键字，则返回对应的值；如果不存在num关键字，则创建一个键值对，键为num，值为值类型的默认初始化值。
        //等号右侧的map[a]先执行。先在map里面找有没有元素为a的。如果没有就创建一个key=a value=0的元素。然后返回value= 0。之后value+1赋值给key为a的元素的value上面
        //先重载=返回自己。然后重载[]返回second也就是value。因为东西是按照pair存的。
    }
    for(auto x = map.begin(); x!= map.end(); x++){
        cout << x->first << x->second << endl;
    }
    
    pair<string,int> ss = *map.begin();
    //map里面的每一个元素可以看为一个pair。注意这里迭代器需要解引用。
    

}