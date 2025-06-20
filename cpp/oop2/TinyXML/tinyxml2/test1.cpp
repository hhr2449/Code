#include "tinyxml2.h"
#include <iostream>
using namespace tinyxml2;
using namespace std;
//!test1用于演示创建xml文件并且输出
void createXML() {
    //创建XMLDocument对象，该对象是文档对象，所有XML元素都是该对象下的
    XMLDocument doc;
    //创建声明<?xml version="1.0" encoding="UTF-8"?>
    doc.InsertEndChild(doc.NewDeclaration());
    //创建注释<!--this is a comment-->
    doc.InsertEndChild(doc.NewComment("this is a comment"));
    //创建根节点<university>
    XMLElement* root = doc.NewElement("university");
    doc.InsertEndChild(root);
    //为根节点添加属性<university name="tsinghua university" established = "1911">
    root->SetAttribute("name", "tsinghua university");
    root->SetAttribute("established", "1911");
    //在根节点下添加子节点<department1>
    XMLElement* department1 = doc.NewElement("department1");
    root->InsertEndChild(department1);
    //为子节点添加属性<department1 name="computer science" studentNum = "210">
    department1->SetAttribute("name", "computer science");
    department1->SetAttribute("studentNum", "210");
    //在节点department1下添加注释<!--this is the department of computer science-->
    XMLComment* comment1 = doc.NewComment("this is the department of computer science");
    department1->InsertEndChild(comment1);
    //在节点department1下添加文本节点<course>oop</course>
    XMLElement* course = doc.NewElement("course");
    course->SetText("oop");
    department1->InsertEndChild(course);
    //在节点department1下添加节点<professor></professor>
    XMLElement* prof1 = doc.NewElement("professor1");
    prof1->SetAttribute("name", "liu");
    prof1->SetText("Atificial Intelligence");
    department1->InsertEndChild(prof1);
    //在根节点下添加节点<department2>
    XMLElement* department2 = doc.NewElement("department2");
    root->InsertEndChild(department2);
    //为子节点添加属性<department2 name="math" studentNum = "50">
    department2->SetAttribute("name", "math");
    department2->SetAttribute("studentNum", "50");
    //在节点department2下添加注释<!--this is the department of math-->
    XMLComment* comment2 = doc.NewComment("this is the department of math");
    department2->InsertEndChild(comment2);
    //在节点department2下添加文本节点<course>calcular</course>
    XMLElement* course2 = doc.NewElement("course");
    course2->SetText("calcular");
    department2->InsertEndChild(course2);
    //在节点department2下添加节点<professor></professor>
    XMLElement* prof2 = doc.NewElement("professor1");
    prof2->SetAttribute("name", "yao");
    prof2->SetText("calcular");
    department2->InsertEndChild(prof2);
    // 添加 <library> 并在其中添加多行文本
    XMLElement* lib = doc.NewElement("library");
    lib->SetAttribute("open", true);
    XMLText* text = doc.NewText("This library opens from 8AM to 10PM.\nBooks on AI, Math, Physics are available.");
    lib->InsertEndChild(text);
    root->InsertEndChild(lib);
    XMLError e = doc.SaveFile("test1.xml");
    if (e == XML_SUCCESS)
        cout << "文件保存成功。" << endl;
    else
        cout << "文件保存失败，错误码: " << e << endl;

}
int main() {
    createXML();
}


//输出应该如下所示
/*--------------------------------------------------------------------|
<?xml version="1.0" encoding="UTF-8"?>
<!--this is a comment-->
<university name="tsinghua university" established="1911">
    <department1 name="computer science" studentNum="210">
        <!--this is the department of computer science-->
        <course>oop</course>
        <professor1 name="liu">Atificial Intelligence</professor1>
    </department1>
    <department2 name="math" studentNum="50">
        <!--this is the department of math-->
        <course>calcular</course>
        <professor1 name="yao">calcular</professor1>
    </department2>
    <library open="true">This library opens from 8AM to 10PM.
Books on AI, Math, Physics are available.</library>
</university>

<!!BADNODE something>
-----------------------------------------------------------------------*/