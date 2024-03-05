// Program with the implementation of assign() function and test code-

#include <iostream>
#include <iomanip>
#include <map>
#include <limits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
template<typename K, typename V>
class interval_map {
    std::map<K,V> m_map;

public:
  // constructor associates whole range of K with val by inserting (K_min, val)
  // into the map
  interval_map( V const& val) {
      m_map.insert(m_map.end(),std::make_pair(std::numeric_limits<K>::lowest(),val));
  }

  // Assign value val to interval [keyBegin, keyEnd).
  // Overwrite previous values in this interval.
  // Conforming to the C++ Standard Library conventions, the interval
  // includes keyBegin, but excludes keyEnd.
  // If !( keyBegin < keyEnd ), this designates an empty interval,
  // and assign must do nothing.
  // implementation of assign function
  void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
        // body of assign() function
        if (!(keyBegin < keyEnd)) return;

        std::pair<K,V> beginExtra;
        std::pair<K,V> endExtra;
        bool beginHasExtra = false;
        bool endHasExtra = false;
// open range for iterator
        typename std::map<K,V>::iterator itBegin;
        itBegin = m_map.lower_bound(keyBegin);
        if ( itBegin!=m_map.end() && keyBegin < itBegin->first ) {
            if (itBegin != m_map.begin()) {
                beginHasExtra = true;
                --itBegin;
                beginExtra = std::make_pair(itBegin->first, itBegin->second);
            }
            
        }
// close range for iterator
        typename std::map<K,V>::iterator itEnd;
        itEnd = m_map.lower_bound(keyEnd);
        if ( itEnd!=m_map.end() && keyEnd < itEnd->first ) {
            endHasExtra = true;
            typename std::map<K,V>::iterator extraIt = itEnd;
            --extraIt;
            endExtra = std::make_pair(keyEnd, extraIt->second);
        }

        // four canonical conflicts
        bool insertMid = true;
        if (beginHasExtra) {
            if (beginExtra.second == val)
                insertMid = false;
        } else {
            if (itBegin != m_map.begin()) {
                typename std::map<K,V>::iterator beforeMid = itBegin;
                --beforeMid;
                if (beforeMid->second == val)
                    insertMid = false;
            }
        }


        if (endHasExtra) {
            if ( (insertMid && endExtra.second == val) || (!insertMid && endExtra.second == beginExtra.second) )
                endHasExtra = false;
        } else {
            if ( (insertMid && itEnd!=m_map.end() && itEnd->second == val) || (!insertMid && itEnd!=m_map.end() && itEnd->second == beginExtra.second) )
                itEnd = m_map.erase(itEnd);
        }

        itBegin = m_map.erase(itBegin, itEnd);
        if (beginHasExtra)
            itBegin = m_map.insert(itBegin, beginExtra);
        if (insertMid)
            itBegin = m_map.insert(itBegin, std::make_pair(keyBegin, val));
        if (endHasExtra)
            m_map.insert(itBegin, endExtra);
  }

  // look-up of the value associated with key
  V const& operator[]( K const& key ) const {
      return ( --m_map.upper_bound(key) )->second;
  }
};
// driver or test code
int main()
{
    // instance of interval_map class
    interval_map<int,char> m('A');
    // calling of assign() function  
    m.assign(1, 3, 'B');
    // loop for maping key and its corresponding value
    for (int i = -2; i <= 5; ++i)
        std::cout << std::setw(2) << i << ' ' << m[i] << '\n';
}