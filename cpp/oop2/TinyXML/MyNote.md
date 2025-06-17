# 1.项目文件解析

## （1）文件夹详解

### `.github/workflows`

- **作用**：GitHub Actions 的自动化构建配置。
- **用途**：当有人 push、pull request 或发布 release 时，会触发这里定义的流程，比如自动编译项目、运行单元测试、发布版本。
- **内容**：通常是一些 `.yml` 或 `.yaml` 文件，比如 `ci.yml`（持续集成）或 `release.yml`（打包发布）。

------

### `cmake`（用来进行项目构建的）

- **作用**：存放 CMake 的辅助模块。
- **用途**：
  - 放置自定义宏、函数，如 `FindTinyXML2.cmake`、`Version.cmake` 等。
  - 支持更复杂的构建需求（跨平台支持、选项配置等）。

------

### `contrib`

- **作用**：第三方贡献代码或样例。
- **可能内容**：
  - 示例扩展（比如与其他库结合）；
  - 额外的工具、脚本或文档；
  - 代码实验或原型。

------

### `docs`（里面的index.html有项目简介和实例）

- **作用**：项目的说明文档。
- **常见内容**：
  - 使用手册（markdown 或 HTML）；
  - API 说明；
  - 架构图或设计原理；
  - 也可能包含 Doxygen 配置或链接。

------

### `resources`

- **作用**：存储运行时资源。
- **可能包括**：
  - 示例 XML 文件；
  - 测试输入数据；
  - 图片或图标；
  - 配置模板（如 JSON、INI）。

------

### `test`

- **作用**：项目的测试代码。
- **包含内容**：
  - 单元测试：测试函数级别功能；
  - 集成测试：测试整个模块行为；
  - 可能使用 GoogleTest、Catch2 或自定义测试框架；
  - 也可能包含 `main()` 函数用于手动测试或命令行测试工具。

------

### `dox`

- **作用**：Doxygen 文档相关。
- **内容可能包括**：
  - `Doxyfile` 配置；
  - 自动生成的 API 文档；
  - 文档模板或图示（类图、调用图）；
  - 一般配合源码注释，生成 HTML/PDF 格式的说明文档。

------

## （2）文件详解

### `.gitignore`

- **作用**：告诉 Git 忽略哪些文件不进行版本控制。

- **内容示例**：

  ```
  bash复制编辑build/
  *.o
  *.log
  *.exe
  CMakeCache.txt
  ```

------

### `CMakeLists.txt`

- **作用**：CMake 构建系统的主入口。

- **内容示例**：

  ```
  cmake复制编辑cmake_minimum_required(VERSION 3.10)
  project(tinyxml2)
  add_library(tinyxml2 tinyxml2.cpp)
  target_include_directories(tinyxml2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
  enable_testing()
  add_executable(xmltest xmltest.cpp)
  ```

------

### `LICENSE.txt`

- **作用**：明确项目的开源协议。
- **常见类型**：MIT、Apache 2.0、GPL 等。
- **法律意义**：声明作者权利及用户使用限制或自由程度。

------

### `Makefile`

- **作用**：手动使用 `make` 命令编译项目的规则文件。

- **用途**：可作为 CMake 的替代方案，提供直接的构建方式（适合小项目或特定平台）。

- **示例内容**：

  ```
  makefile复制编辑all:
      g++ tinyxml2.cpp xmltest.cpp -o xmltest
  ```

------

### `TinyXML2_small.png`

- **作用**：项目相关的图片资源。
- **可能用途**：
  - README 文档中的展示图；
  - Doxygen 文档封面；
  - GitHub 项目头像。

------

### `meson.build`

- **作用**：Meson 构建系统的主配置文件。

- **Meson 是什么**：一个比 CMake 更快更现代的构建系统。

- **内容示例**：

  ```
  meson复制编辑project('tinyxml2', 'cpp')
  libtinyxml2 = static_library('tinyxml2', 'tinyxml2.cpp')
  ```

------

### `meson_options.txt`

- **作用**：定义构建时的可选项。

- **例如**：

  ```
  meson
  
  
  复制编辑
  option('build_tests', type : 'boolean', value : true, description : 'Build test suite')
  ```

------

### `readme.md`

- **作用**：GitHub 项目的主说明文件。
- **通常包括**：
  - 项目简介；
  - 安装方法；
  - 使用示例；
  - 贡献指南；
  - License 信息。

------

### `setversion.py`

- **作用**：自动设置或更新版本号的 Python 脚本。
- **用途**：
  - 修改源码中的 `#define TINYXML2_VERSION "9.0.0"`；
  - 更新文档或打包文件的版本标记；
  - 可能会作为 CI 构建流程的一部分调用。

------

### `tinyxml2.cpp` 和 `tinyxml2.h`  （主要看的是这两个）

- **作用**：项目的核心源码。
- `tinyxml2.cpp`：
  - 实现 XML 解析、节点结构、读取写入功能；
  - 支持 DOM 样式访问或流式解析。
- `tinyxml2.h`：
  - 对外暴露的 API 接口；
  - 类定义、函数声明。

------

### `xmltest.cpp`

- **作用**：用于测试 TinyXML2 功能的主程序。
- **可能实现**：
  - 创建 XML；
  - 加载并解析 XML；
  - 修改节点内容；
  - 验证库功能是否正确。

# 2.XML粗略学习

## （1）概述

同样的数据可能会在不同的地方使用（比如天气预报的数据，有相关单位发布，很多APP和网站都会需要获取相关数据）

不同的网站可能会使用不同的语言构建，所以数据应该可以兼容所有的语言，也就是需要找到一种不同语言都可以解析的数据传输格式

![image-20250614213112103](https://raw.githubusercontent.com/hhr2449/pictureBed/main/img/image-20250614213112103.png)

也就是XML数据格式

XML数据格式的最主要的功能就是数据传输，在不同的程序之间传输数据

配置文件：一个网站可能不能只使用一种语言，在书写配置文件的时候就需要一种通用的格式

规范数据格式，是数据具有结构性，易读易处理

* XML:可扩展性标记语言
* XML被发明的目的是传输和存储数据，而不是展示数据，HTML则是用于展示数据
* XML的标签必须自定义，没有官方标签，但是在写标签名的时候一定要有含义（就像变量名要有含义）

## （2）如何书写

1. 文件后缀名为xml

2. <tag>具体数据</tag>

3. 标签名不能有任何的中文字符和空格

4. 使用的编码格式应该是utf-8

5. 所有的标签应该用<root></root>根节点括起来

   ![image-20250614213129126](https://raw.githubusercontent.com/hhr2449/pictureBed/main/img/image-20250614213129126.png)

![image-20250614213139840](https://raw.githubusercontent.com/hhr2449/pictureBed/main/img/image-20250614213139840.png)

* **XML 必须有根节点；**

根节点就是所有节点的父级节点

* **XML 头声明：可有可无**

  ![image-20250614214915411](https://raw.githubusercontent.com/hhr2449/pictureBed/main/img/image-20250614214915411.png)

version:版本，encoding:编码格式，注意?后面没有空格

可有可无，但是建议书写

* 所有XML节点都必须是成对标签

* 标签名对大小写敏感

* 标签不允许交叉

  ![image-20250614215514647](https://raw.githubusercontent.com/hhr2449/pictureBed/main/img/image-20250614215514647.png)

  标签里面套一个标签是允许的

  ![image-20250614215500242](https://raw.githubusercontent.com/hhr2449/pictureBed/main/img/image-20250614215500242.png)

但是不能交叉使用标签，也就是从中间向两边，标签必须两两对应

* 注释格式<!-- -->

  ![image-20250614215853884](https://raw.githubusercontent.com/hhr2449/pictureBed/main/img/image-20250614215853884.png)

注释掉的东西不参与解析 

* 实体编码

![image-20250614220607650](https://raw.githubusercontent.com/hhr2449/pictureBed/main/img/image-20250614220607650.png)

![image-20250614220622139](https://raw.githubusercontent.com/hhr2449/pictureBed/main/img/image-20250614220622139.png)

< >等特殊字符不能够直接表示，应该使用实体转义

| 实体编码 | 代表字符 | 含义       |
| -------- | -------- | ---------- |
| `&lt;`   | <        | less than  |
| `&gt;`   | >        | great than |
| `&amp;`  | &        | ampersand  |
| `&apos;` | '        | apostrophe |
| `&quot;` | "        | quot       |

### 属性

属性是用于补充标签的相关信息的

比如html中的<img>标签中 <img src="" width="" height="">

src补充了图片的地址，width是图片的宽度，height是图片的高度，这些就是图片标签的属性

![image-20250615093013570](https://raw.githubusercontent.com/hhr2449/pictureBed/main/img/image-20250615093013570.png)

展示效果如下

![image-20250615093021982](https://raw.githubusercontent.com/hhr2449/pictureBed/main/img/image-20250615093021982.png)

下面就是一个xml的标签

![image-20250615094348312](https://raw.githubusercontent.com/hhr2449/pictureBed/main/img/image-20250615094348312.png)

![image-20250615094400185](https://raw.githubusercontent.com/hhr2449/pictureBed/main/img/image-20250615094400185.png)

* 一个标签可以有多个属性
* 属性的值必须使用引号引起来
* 命名规则：数字，字母，下划线，数字不能开头
* 属性就是用于表示标签自身的一些额外信息的，在xml中标签完全是人为自定义的，所以属性的意义不大，可以创建其他的标签来表示
* 在解析xml数据的时候，属性会带来额外的解析代码，比较麻烦

### CDATA区域
* 语法：<![CDATA[内容]]>

* 在CDATA区域中，内容不会被解析，也就是可以正常的使用<,>,&,"",''等字符而不用进行实体转义

  例子如下：

  ![image-20250615100207526](https://raw.githubusercontent.com/hhr2449/pictureBed/main/img/image-20250615100207526.png)

![image-20250615100220010](https://raw.githubusercontent.com/hhr2449/pictureBed/main/img/image-20250615100220010.png)

* 当特殊字符较少时使用实体转移，当特殊字符较多时使用CDATA



## （3）解析XML数据

### 如何解析

 xml中的所有东西实质上都是字符串，只是这串字符串是由一定的规则的（标签，属性，内容，CDATA，头声明等）

  



## 3.尝试实现XML解析器



### （1）API设计与实现

#### XML文档的格式

* 节点（node）或者说是元素（element）

  ```xml
  <?xml version="1.0" encoding="utf-8"?>
  <students>
  	<student id="1" class="101">
  		<name>大明</name>
  		<age>14</age>
  		<gender>male</gender>
  	</student>
  	<student id="2" class="102">
  		<name>玲玲</name>
  		<age>15</age>
  		<gender>female</gender>
  	</student>
  	<student id="3" class="103">
  		<name>汤姆</name>
  		<age>16</age>
  		<gender>male</gender>
  	</student>
  </students>
  ```

xml的结构是一个树状的结构，以这个为例：

* students是一个根节点
* 根节点一下有三个student子节点
* 每个student节点又有name,age,gender三个子节点
* student节点有id和class两个属性

#### API设计

设计类：Xml（就是Xml中的节点）,最后我们会将Xml文件解析为一个Xml类，方便使用

成员变量：每个节点有名称，内容，属性，可能会有子节点

名称和内容一定会有，可以使用string来表示

属性可有可无，而且其是由属性名和属性内容构成的，所以可以使用键值对map来表示

子节点可以使用list来维护

考虑效率问题，如果简单的使用string等值方式来储存数据，那么进行数据的拷贝的时候会出现深度拷贝从而降低效率，所以使用指针来维护数据

1. 构造函数：包含四种构造方式

直接构造，传入name构造（包含string和char *两种），拷贝构造

2. name相关操作

   * getName()获取节点的名称（没有设置名称则返回空字符串）
   * setName()设置节点的名称（注意如果不是空指针，则应该先delete再new

3. content相关操作

   * 和name类似，get和set

4. attribute相关操作

   * getAttri():传入属性名key，获取key对应的属性值，注意如果没有则返回空
   * setAttri():传入key和value，建立一个新的属性
   * rmAttri():根据key删除key对应的那条属性

5. child相关操作

   * 仍然是访问，设置，删除的思路

   * 访问：重载[]运算符

     1. 通过下标访问：先验证范围，超出范围抛出错误，然后使用迭代器获取对应下标的子节点
     2. 通过名称访问：遍历所有子节点，返回第一个符合名称的子节点，注意这里如果找不到节点则新建一个

   * 加入节点：addChild()函数：传入一个Xml对象，直接push_back即可

   * 删除节点：

     1. 这里要特别注意，我们是使用指针来管理相关数据的，所以在清除的时候要清除指针指向的内存

     2. 成员函数clear():用于清除节点，其中name,content,attribute好清理，直接delete然后置空即可，但是要注意child，这个是一个储存了Xml类型数据的list，所以清除节点的时候要遍历child，递归清除子节点

        clear()的使用要注意，很容易产生重复delete的错误（因为清除节点后如果该节点是子节点，那么它的空指针任然存在于某个节点的child list里），必须保证：要么直接清除根节点，要么清除节点的同时把list中的对应节点清除

     3. rmChild()：根据索引或者名称清除节点，只需要找到对应节点，然后调用clear并且erase list中对应部分即可

   * 为了实现类似其他容器的操作，实现了begin(),end(),erase(),size()函数，只需要调用child中相关函数即可实现

6. 格式化输出

   * 维护一个sstream，将各种元素按照Xml文件的相关格式排列进去即可

### （2）paser的实现

```cpp
//
// Created by Alone on 2022-8-8.
//

#include "Parser.h"

using namespace xml;

#include<fstream>

using std::ifstream;

#include<sstream>

using std::ostringstream;

#include<filesystem>


void xml::Parser::LoadFile(const string &filename)//传入文件名
{
    ifstream ifs(filename);//打开文件
    if (!ifs)//如果打不开文件，那么输出错误信息
    {

        ostringstream info;
        info << "load file error:file path not exist! path:" << filename;
        info << " current path:" << std::filesystem::current_path();
        throw std::runtime_error(info.str());//抛出异常同时输出报错信息info
    }
    m_str = std::move(string(std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>()));//将字符串读入paser中的字符串
    m_idx = 0;
    _trim_right();//去除空白字符
}

void xml::Parser::LoadString(string_view content)//通过字符串来加载
{
    m_str = content;
    m_idx = 0;
    //去除左右边的多余空白字符
    _trim_right();
}

Element xml::Parser::FromFile(const string &filename)
{
    static Parser instance;//创建paser的实例
    instance.LoadFile(filename);//加载xml文件
    return instance.Parse();//对paser实例进行解析，返回我们最终目标的Element对象
}

Element xml::Parser::FromString(string_view content)
{
    static Parser instance;
    instance.LoadString(content);
    return instance.Parse();
}

//用于返回较为详细的错误信息，方便错误追踪
#define THROW_ERROR(error_info, error_detail) \
    do{                                    \
    string info = "parse error in ";              \
    string file_pos = __FILE__;                          \
    file_pos.append(":");                                \
    file_pos.append(std::to_string(__LINE__));\
    info += file_pos;                                  \
    info += ", ";                          \
    info += (error_info);                    \
    info += "\ndetail:";                          \
    info += (error_detail);\
    throw std::logic_error(info); \
}while(false)

//m_idx是一个记录，用于记录解析到了m_str中的第几个字符
char xml::Parser::_get_next_token()//用于返回下一个非空字符
{
    while (m_idx < m_str.size() && isspace(m_str[m_idx]))//跳过空字符（不能超过范围）
    {
        m_idx++;
    }
    if (m_idx >= m_str.size())//如果超过范围，报错
        THROW_ERROR("invalid format", "out of length");
    return m_str[m_idx];//返回字符
}

void xml::Parser::_trim_right()//删除两侧的空格
{
    m_str.erase(std::find_if(m_str.rbegin(), m_str.rend(), [](char x)
    {
        return !isspace(x);
    }).base(), m_str.end());
    if (m_str.back() != '>') //格式的验证
        THROW_ERROR("format error,expected '>'", m_str.substr(m_str.size() - detail_len));
}


Element xml::Parser::Parse()//解析主流程，对paser类的对象进行解析，返回解析完成得到的Element
{
    while (true)
    {
        char t = _get_next_token();//返回下一个非空字符

        if (t != '<')//如果不是<，则为格式错误
        {
            THROW_ERROR("invalid format", m_str.substr(m_idx, detail_len));
        }

        //解析版本号 //头声明的前面一定是<?xml
        if (m_idx + 4 < m_str.size() && m_str.compare(m_idx, 5, "<?xml") == 0)
        {//版本号不用放进最终的元素中
            if (!_parse_version())
            {
                THROW_ERROR("version parse error", m_str.substr(m_idx, detail_len));
            }
            continue;
        }

        //解析注释   //注释开头一定是<!--
        if (m_idx + 3 < m_str.size() && m_str.compare(m_idx, 4, "<!--") == 0)
        {//与之前版本号的思路类似，查找最后的闭合符号，没有找到报错，找到了跳过进入下一轮搜索
            if (!_parse_comment())
            {
                THROW_ERROR("comment parse error", m_str.substr(m_idx, detail_len));
            }
            continue;
        }

        //解析element  //处理<后面跟的是标签的情况，注意xml中标签名一定是紧跟<的，所以可以直接使用<后面的字符来判断
        if (m_idx + 1 < m_str.size() && (isalpha(m_str[m_idx + 1]) || m_str[m_idx + 1] == '_'))
        {
            return _parse_element();//进一步调用函数进行解析
        }

        //出现未定义情况直接抛出异常
        THROW_ERROR("error format", m_str.substr(m_idx, detail_len));
    }
}

bool xml::Parser::_parse_version()
{
    auto pos = m_str.find("?>", m_idx);//从当前位置开始查找?>，是头声明结束的标志
    if (pos == string::npos)//如果没有找到，说明有错，返回false
    {
        return false;
    }
    m_idx = pos + 2;//如果找到了，则跳到?>之后，开始下一轮查找
    return true;
}


bool xml::Parser::_parse_comment()
{
    auto pos = m_str.find("-->", m_idx);
    if (pos == string::npos)
    {
        return false;
    }
    m_idx = pos + 3;
    return true;
}


Element xml::Parser::_parse_element()
{
    Element element;
    //以一个完整的节点作为单位进行解析，在开始标签处(以<+name为标志)创建element，在结束处（以结束标签为标志）返回得到的element，如果有子节点就递归调用，并且push_back进XmlChild
    auto pre_pos = ++m_idx; //过掉< 此时pre_pos指向name的第一个字符
    //判断name首字符合法性
    if (!(m_idx < m_str.size() && (std::isalpha(m_str[m_idx]) || m_str[m_idx] == '_')))
    {
        THROW_ERROR("error occur in parse name", m_str.substr(m_idx, detail_len));
    }

    //解析name 向后移直到m_idx移到第一个非name字符
    //想想此时m_idx可能移动到哪里
    //<name> <name age="10"> <name >
    //可能移动到>，此时头标签已经结束，可能移动到属性前面的空格，可能name后面有空格
    while (m_idx < m_str.size() && (isalpha(m_str[m_idx]) || m_str[m_idx] == ':' ||
                                    m_str[m_idx] == '-' || m_str[m_idx] == '_' || m_str[m_idx] == '.'))
    {
        m_idx++;
    }

    if (m_idx >= m_str.size())
        THROW_ERROR("error occur in parse name", m_str.substr(m_idx, detail_len));

    element.Name() = m_str.substr(pre_pos, m_idx - pre_pos);//将name截取出来
    
    //思考name之后的非空字符的情况：
    //1.'/'这是单标签，<element />,与空标签等效
    //2.标签属性
    //3.当前已经到了标签的>，下一个可能是结束标签，注释，子节点
    //3.1结束标签：</ 3.2注释<!--  3.3下一个节点（递归调用并且将结果push_back）
    //4.标签没有属性，但是name后面有一个空格，所以非空字符应该是>
    //4.1 > 之后可能跟着该标签的text，可能是子节点，可能是注释，可能是结束符
    

    //正式解析内部
    while (m_idx < m_str.size())
    {
        char token = _get_next_token();
        if (token == '/') //1.单元素，直接解析后结束
        {
            if (m_str[m_idx + 1] == '>')
            {
                m_idx += 2;
                return element;
            } else
            {
                THROW_ERROR("parse single_element failed", m_str.substr(m_idx, detail_len));
            }
        }

        if (token == '<')//2.对应三种情况：结束符、注释、下个子节点
        {
            //结束符
            if (m_str[m_idx + 1] == '/')
            {
                if (m_str.compare(m_idx + 2, element.Name().size(), element.Name()) != 0)
                {
                    THROW_ERROR("parse end tag error", m_str.substr(m_idx, detail_len));
                }

                m_idx += 2 + element.Name().size();
                char x = _get_next_token();
                if (x != '>')
                {
                    THROW_ERROR("parse end tag error", m_str.substr(m_idx, detail_len));
                }
                m_idx++; //千万注意把 '>' 过掉，防止下次解析被识别为初始的tag结束，实际上这个element已经解析完成
                return element;
            }
            //是注释的情况
            if (m_idx + 3 < m_str.size() && m_str.compare(m_idx, 4, "<!--") == 0)
            {
                if (!_parse_comment())
                {
                    THROW_ERROR("parse comment error", m_str.substr(m_idx, detail_len));
                }
                continue;
            }
            //其余情况可能是注释或子元素，直接调用parse进行解析得到即可（递归调用，将子元素放入）
            element.push_back(Parse());
            continue;
        }
        if (token == '>') //3.对应两种情况：该标签的text内容
            //下个标签的开始或者注释（直接continue跳到到下次循环即可）
            //这里只用处理之后的是text的情况，如果后面是注释或者子节点，那么之后的非空字符一定是 < ，这样就可以直接continue到前面的if (token == '<')进行处理
        {
            m_idx++;
            //判断下个token是否为text，如果不是则continue
            char x = _get_next_token();
            if (x == '<')//直接continue到前面的if (token == '<')进行处理
            {
                continue;
            }
            //解析text，解析完后直接continue，将后面的 < 交给if (token == '>')分支处理
            auto pos = m_str.find('<', m_idx);
            if (pos == string::npos)
                THROW_ERROR("parse text error", m_str.substr(m_idx, detail_len));
            element.Text() = m_str.substr(m_idx, pos - m_idx);
            m_idx = pos;
            //注意：有可能直接碰上结束符，所以需要continue，让element里的逻辑来进行判断
            continue;
        }

        //4.其余情况都为属性的解析

        auto key = _parse_attr_key();
        auto x = _get_next_token();
        if (x != '=')
        {
            THROW_ERROR("parse attrs error", m_str.substr(m_idx, detail_len));
        }
        m_idx++;
        auto value = _parse_attr_value();
        element[key] = value;
    }

    THROW_ERROR("parse element error", m_str.substr(m_idx, detail_len));
}


string xml::Parser::_parse_attr_key()
{
    char token = _get_next_token();
    auto start_pos = m_idx;
    if (isalpha(token) || token == '_')
    {
        while (m_idx < m_str.size() &&
               (isalpha(m_str[m_idx]) || isdigit(m_str[m_idx]) ||
                m_str[m_idx] == '_' || m_str[m_idx] == '-' || m_str[m_idx] == ':')
               && m_str[m_idx] != '=')
        {
            m_idx++;
        }
        return m_str.substr(start_pos, m_idx - start_pos);
    }
    THROW_ERROR("parse attr key error", m_str.substr(m_idx, detail_len));
}

string xml::Parser::_parse_attr_value()
{
    char token = _get_next_token();
    if (token == '"')
    {
        auto start_pos = ++m_idx;
        auto pos = m_str.find_first_of('"', m_idx);
        if (pos == string::npos)
        {
            THROW_ERROR("parse attr value error", m_str.substr(m_idx, detail_len));
        }
        m_idx = pos + 1;
        return m_str.substr(start_pos, pos - start_pos);
    }
    THROW_ERROR("parse attr key error", m_str.substr(m_idx, detail_len));
}
```





