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
    /// Reaturn.xaml 的交互逻辑
    /// </summary>
    public partial class Reaturn : Window
    {
        public Reaturn()
        {
            InitializeComponent();
        }

        private void Cancle(object sender, RoutedEventArgs e)
        {
            Application.Current.Shutdown();
        }

        private void clickReturn(object sender, RoutedEventArgs e)
        {
            if (putInBooklist())
            {


                string dataSource = "(DESCRIPTION = (ADDRESS = (PROTOCOL = TCP)(HOST = localhost)(PORT = 1521))(CONNECT_DATA = (SERVICE_NAME = orcl)))";
                string loginStr = "user id=system" + ";" + "password=orcl" + ";" + "data source=" + dataSource;
                OracleConnection conn = new OracleConnection(loginStr);
                try
                {
                    //在保存用户的表中中查询登录的账号的借书信息
                    conn.Open();
                    OracleCommand cmd = new OracleCommand(" ", conn);
                    cmd.CommandText = "delete from user16103217 where booknumber=" + booknumber.Text;
                    int a = cmd.ExecuteNonQuery();

                    MessageBox.Show("还书成功", "成功", MessageBoxButton.OK, MessageBoxImage.Information);
                }
                catch
                {
                    MessageBox.Show("还书失败", "失败", MessageBoxButton.OK, MessageBoxImage.Information);
                }
            }
        }
        private bool putInBooklist()
        {
            string dataSource = "(DESCRIPTION = (ADDRESS = (PROTOCOL = TCP)(HOST = localhost)(PORT = 1521))(CONNECT_DATA = (SERVICE_NAME = orcl)))";
            string loginStr = "user id=system" + ";" + "password=orcl" + ";" + "data source=" + dataSource;
            OracleConnection conn = new OracleConnection(loginStr);
            string Input = "insert into booklist select * from user16103217 where booknumber=" + booknumber.Text;
            try
            {
                conn.Open();
                OracleCommand cmd = new OracleCommand(Input, conn);
                cmd.ExecuteNonQuery();
                return true;
            }
            catch
            {
                MessageBox.Show("还书失败", "失败", MessageBoxButton.OK, MessageBoxImage.Information);
                return false;
            }
        }
    }
}
