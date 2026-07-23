#include <iostream>
#include <string>

class MusicPlayerBad{
    int* volume_;

public:
    MusicPlayerBad(int vol){
        volume_ = new int(vol);
        std::cout<<"音量已设置: "<<*volume_<<std::endl;
    }

    int get_volume() const{
        return *volume_;
    }
};

class MusicPlayer{
    int* volume_;
    std::string* song_name_;

public:
    MusicPlayer(int vol, const std::string& song) : volume_(new int(vol)), song_name_((new std::string(song))){
        std::cout << "🎵 正在播放: " << *song_name_ << " (音量: " << *volume_ << ")" << std::endl;
    }

    ~MusicPlayer(){
        std::cout << "⏹️ 停止播放: " << *song_name_;
        delete volume_;
        delete song_name_;
        std::cout<<"内存已经释放"<<std::endl;
    }

    void set_volume(int vol){
        *volume_ = vol;
    }
    int get_volume() const {
        return *volume_;
    }

    std::string get_song() const {
        return *song_name_;
    }
};

void test_raii(){
    MusicPlayer mp(70, "Bohemian Rhapsody");
    mp.set_volume(50);
    std::cout<<"当前音量: "<<mp.get_volume()<<std::endl;
}

void test_bad(){
    MusicPlayerBad mp(70);
}

class IntArray{
    int* data_;
    int size_;

public:
    IntArray(int size) : size_(size), data_(new int[size]){
        std::cout<<"IntArray 构造: "<<size_<<"个元素"<<std::endl;
    }

    ~IntArray(){
        delete[] data_;
        std::cout<<"IntArray 析构"<<size_<<"个元素已释放"<<std::endl;
    }

    int& operator[](int index){
        return data_[index];
    }
    int size() const {
        return size_;
    }
};

int main(){
    std::cout << "========== RAII 自动释放 ==========" << std::endl;
    test_raii();

    std::cout << "\n========== 坏版本（泄漏）==========" << std::endl;
    test_bad(); 

    std::cout << "\n========== RAII 数组管理 ==========" << std::endl;
    {
        IntArray arr(5);
        for(int i = 0;i<arr.size();i++)
            arr[i] = i * 10;
        for(int i = 0;i<arr.size();i++)
            std::cout<<arr[i]<<" ";
        std::cout<<std::endl;
    }
    

    std::cout << "\n========== 多个对象 ==========" << std::endl;
    MusicPlayer mp1(30, "Hotel California");
    MusicPlayer mp2(50, "Stairway to Heaven");

    return 0;
}