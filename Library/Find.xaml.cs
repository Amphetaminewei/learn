using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;
using System.Collections.ObjectModel;
using Oracle.ManagedDataAccess.Client;

namespace Library
{

    /// <summary>
    /// Window1.xaml 的交互逻辑
    /// </summary>
    public partial class Find : Window
    {
        public static string userId;

        public Find()
        {
            InitializeComponent();
        }

        private void clickFind(object sender, RoutedEventArgs e)
        {
            //用来保存从表中得到的信息
            ObservableCollection<ReaderBook> borrowData = new ObservableCollection<ReaderBook>();

            string dataSource = "(DESCRIPTION = (ADDRESS = (PROTOCOL = TCP)(HOST = localhost)(PORT = 1521))(CONNECT_DATA = (SERVICE_NAME = orcl)))";
            string loginStr = "user id=system" + ";" + "password=orcl" + ";" + "data source=" + dataSource;
            OracleConnection conn = new OracleConnection(loginStr);
            try
            {
                //在保存用户的表中中查询登录的账号的借书信息
                conn.Open();
                OracleCommand cmd = new OracleCommand(" ", conn);
                cmd.CommandText = "select * from user" + login();
                OracleDataReader reader = cmd.ExecuteReader();
                while (true)
                {
                    reader.Read();
                    borrowData.Add(new ReaderBook()
                    {
                        BookName = reader["bookname"].ToString(),
                        BookId = int.Parse(reader["booknumber"].ToString()),
                        PublishingHouse = reader["publishinghouse"].ToString(),
                        Author = reader["authorname"].ToString(),
                        ISBN = int.Parse(reader["ISBN"].ToString()),
                        //BorrowTime = reader["borrowdate"].ToString()
                    });
                    dataGrid.DataContext = borrowData;
                }
                
            }
            catch (Exception ex)
            {

            }
        }

        private string login()
        {
            string dataSource = "(DESCRIPTION = (ADDRESS = (PROTOCOL = TCP)(HOST = localhost)(PORT = 1521))(CONNECT_DATA = (SERVICE_NAME = orcl)))";
            string loginStr = "user id=system" + ";" + "password=orcl" + ";" + "data source=" + dataSource;
            OracleConnection conn = new OracleConnection(loginStr);
            try
            {
                //在表中查询登录信息
                conn.Open();
                OracleCommand cmd = new OracleCommand(" ", conn);
                //cmd.CommandText = "select * from user16103217";
                cmd.CommandText = "select * from login where userid=" + userName.Text;
                OracleDataReader readLogin = cmd.ExecuteReader();
                readLogin.Read();
                string psw = readLogin["userpassword"].ToString();
                string userid = readLogin["userid"].ToString();
                conn.Close();
                readLogin.Close();

                if (psw == password.Password)
                {
                    //登录成功则返回登录的学号
                    MessageBox.Show("登录成功", "成功", MessageBoxButton.OK, MessageBoxImage.Information);
                    userId = userid;
                    return userid;
                }
                else
                {
                    return null;
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("登录失败");
                return null;
            }
        
    }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            Application.Current.Shutdown();
        }
    }

}
