### 1.StrPair

* 管理和处理 XML 中字符串片段 的核心工具类。

* 这个类封装了一段字符串的起始指针，同时根据解析上下文控制对字符串的 换行处理、实体转义、空白折叠等操作。

*  int   _flags;//控制字符串是否需要处理（删除，转义，刷新）
char*  _start;//指向字符串起始位置的指针

char*  _end;//指向字符串结束位置的指针

### 2.DynArray
* DynArray是TinyXml2中自己实现的一个动态数组

* 功能类似std::vector
  轻量无依赖：不使用 STL，适配嵌入式平台或非 C++ 标准库环境。
  高性能：初始化时使用预分配的栈内存 _pool，避免小数组频繁堆分配。
  
*   T*  _mem;//当前使用的内存地址
    T   _pool[INITIAL_SIZE];//这是一个栈上的小数组，因为想要在堆上创建一个数组的开销是比较大的，
    所以在数据量较小的情况下先使用栈上创建的小数组，等到使用的内存量大于该数组后再使用堆上的数组
    size_t _allocated;		// objects allocated     分配的总容量
    size_t _size;			// number objects in use   元素数量
    
* DynArray() :

  ​    _mem( _pool ),//初始使用的内存是栈上的小数组_pool

  ​    _allocated( INITIAL_SIZE ),

  ​    _size( 0 )

    {

    }

* ~DynArray() {

  ​    if ( _mem != _pool ) {//如果使用的数组不是栈上的，则释放堆上的内存

  ​      delete [] _mem;

  ​    }

    }

* void EnsureCapacity( size_t cap ) {//扩容函数，如果容量不够，则扩出两倍的容量，并将原数据迁移

* 支持获取数据，插入数据，清除等操作

### 3.MemPool内存池基类（使用了类的继承和多态！！！）

```//内存池用于分配和释放许多小而频繁使用的内存
在解析 XML 文档时，会频繁创建大量小对象（节点、文本、属性等），如果每次用 new/delete 来分配和释放：
会导致大量系统开销（慢！）
会产生堆碎片（不连续内存，影响性能）
会变慢或甚至泄漏
```

```
//!设计内存池基类的目的：
//!解析器中有多个不同的对象会需要使用内存池，设计内存池基类就可以通过基类的指针来同一管理所有的内存池
//!比如说使用基类指针数组来管理当前创建的所有内存池，方便资源的同一管理和释放，如下例：
/*MemPool* pools[] = { &_elementPool, &_textPool, &_nodePool };
for (int i = 0; i < 3; ++i) {
  pools[i]->Clear();  // 多态调用，每个池自己释放资源
}*/
//!体现了面向对象设计中的开闭原则：如果想要对池加入其他功能，只要继承即可
```

### 4.XMLVisitor这里涉及设计模式：访问者模式

```cpp
virtual ~XMLVisitor() {}

    /// Visit a document.
    virtual bool VisitEnter( const XMLDocument& /*doc*/ )			{
        return true;
    }
    /// Visit a document.
    virtual bool VisitExit( const XMLDocument& /*doc*/ )			{
        return true;
    }

    /// Visit an element.
    virtual bool VisitEnter( const XMLElement& /*element*/, const XMLAttribute* /*firstAttribute*/ )	{
        return true;
    }
    /// Visit an element.
    virtual bool VisitExit( const XMLElement& /*element*/ )			{
        return true;
    }

    /// Visit a declaration.
    virtual bool Visit( const XMLDeclaration& /*declaration*/ )		{
        return true;
    }
    /// Visit a text node.
    virtual bool Visit( const XMLText& /*text*/ )					{
        return true;
    }
    /// Visit a comment node.
    virtual bool Visit( const XMLComment& /*comment*/ )				{
        return true;
    }
    /// Visit an unknown node.
    virtual bool Visit( const XMLUnknown& /*unknown*/ )				{
        return true;
    }
```



