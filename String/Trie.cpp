#include <bits/stdc++.h>
using namespace std;
const int MAXN = 26;//假设只包含小写字母a-z
struct TrieNode
{
    bool isEnd; //是否为单词结尾
    TrieNode *child[MAXN];//子节点指针数组
    //构造函数 初始化
    TrieNode()
    {
        isEnd=false;
        for (int i = 0; i < MAXN; i++)
        {
            child[i]=nullptr;
        }
    }
    //析构函数 递归释放内存
    ~TrieNode()
    {
        for (int i = 0; i < MAXN; i++)
        {
            if (child[i] != nullptr)
            {
                delete child[i];
            }
        }
    }
};
struct Trie
{
    TrieNode *root; //根节点
    Trie()
    {
        root = new TrieNode();
    }
    //插入单词
    void insert(string word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            int index = c - 'a';
            if (node->child[index] == nullptr)
            {
                node->child[index] = new TrieNode();
            }
            node = node->child[index];
        }
        node->isEnd = true; //标记单词结尾
    }
    //搜索单词
    bool search(string word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            int index = c - 'a';
            if (node->child[index] == nullptr)
            {
                return false;
            }
            node = node->child[index];
        }
        return node->isEnd;
    }

    //搜索前缀
    bool startsWith(string prefix)
    {
        TrieNode *node = root;
        for (char c : prefix)
        {
            int index = c - 'a';
            if (node->child[index] == nullptr)
            {
                return false;
            }
            node = node->child[index];
        }
        return true;
    }

    //析构函数 删除根节点
    ~Trie()
    {
        delete root;
    }
};
int main()
{
    Trie trie;
    trie.insert("hello");
    cout << trie.search("hello") << endl;
    cout << trie.startsWith("hel") << endl;
    return 0;
}