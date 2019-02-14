#include <iostream>
#include <vector>

using namespace std;



template<class T>
class Series {
private:
    vector<T> data_;
public:
    Series() : data_({}) {}
    Series(vector<T> data) : data_(data) {}
    Series(const Series& mSeries) : data_(mSeries.data) {}
    //friend ostream& operator<<(ostream& os, const Series& series);
    friend ostream& operator<<(ostream& os, const Series<T>& series) {
        for (auto item : series.data_) {
            os << item << ' ';
        }
        os << '\n';
        return os;
    }
    T firstDiff(const int id);

};


template<class T>
T Series<T>::firstDiff(const int id) {
    if (data_.size() > 1 && id > 0 && id < data_.size()) {
        return data_[id] - data_[id - 1];
    }
    return -1; // invalid value
}


int main()
{
    vector<int> vec{4, 5, 10, 8, 9};
    Series<int> s1(vec);
    cout << s1.firstDiff(2);
    return 0;
}
