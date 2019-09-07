使用oracle 11g结合WPF的图书管管理系统，只实现了基础的功能


数据库的设计为三个表 login、user16103217、booklist，
每多一个用户就多一个类似user+账号的表，用来存储用户的借书数据
login表保存了用户的账号密码信息，用以验证登录
booklist表为书库的全部书籍信息

booklist 表结构
 名称                                      是否为空? 类型
 ----------------------------------------- -------- ----------------------------
 BOOKNAME                                           VARCHAR2(100)
 BOOKNUMBER                                         NUMBER
 PUBLISHINGHOUSE                                    VARCHAR2(100)
 AUTHORNAME                                         VARCHAR2(100)
 ISBN                                               NUMBER


login表结构
 名称                                      是否为空? 类型
 ----------------------------------------- -------- ----------------------------
 USERID                                             NUMBER
 USERPASSWORD                                       VARCHAR2(20)

user16103217表结构
 名称                                      是否为空? 类型
 ----------------------------------------- -------- ----------------------------
 BOOKNAME                                           VARCHAR2(100)
 BOOKNUMBER                                         NUMBER
 PUBLISHINGHOUSE                                    VARCHAR2(100)
 AUTHORNAME                                         VARCHAR2(100)
 ISBN                                               NUMBER


在用户表中应该加入一列用来保存借书时间的，但是没加蒽，加上之后只需要改动功能中的借书模块中将booklist中的数据移入user表的过程即可（因为加上后会发生数据不足）