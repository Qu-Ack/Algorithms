#include <iostream>

//  0 1 2 3 4
// [0,1,2,3,4]

class UF {
    int members[5];
    public: 
        UF()
        {
            for(int i = 0; i < 5; i++)
            {
                members[i] = i;
            }
        }

        void _union(int p , int q)
        {
            int x = members[p];
            int y = members[q];
            for (int i = 0 ; i < 5; i++)
            {
                if (members[i] == x)
                {
                    members[i] = y;
                }
            }
        }

        bool find(int p , int q)
        {
            return members[p] == members[q];
        }
};


class UF_IMP {
    int id[5];
    private:
        int root(int index)
        {
            // int value_at_index = id[index];
            while(index != id[index])
            {
                index = id[index];
                // keep moving up 
            }
            return index;
        }
    public:
        UF_IMP()
        {
            for (int i = 0; i < 5; i++) id[i] = i;
        }

        void _union(int p , int q)
        {
            int x = root(p);
            id[x] = root(q);
        }

        bool _find(int p , int q)
        {
            return root(p) == root(q);
        }
};


class UF_WEIGHTED {
    int id[5];
    private:
        int root(int index)
        {
            // int value_at_index = id[index];
            while(index != id[index])
            {
                index = id[index];
                // keep moving up 
            }
            return index;
        }
    public:
        UF_WEIGHTED()
        {
            for (int i = 0; i < 5; i++) id[i] = i;
        }

        void _union(int p , int q)
        {
            int x = root(p);
            id[x] = root(q);
        }
 
        bool _find(int p , int q)
        {
            return root(p) == root(q);
        }
};

int main()
{
    UF_IMP uf{};
    uf._union(3,2);
    uf._union(2, 4);
    uf._union(1, 4);
    std::cout << uf._find(0,4) << '\n';
    
}