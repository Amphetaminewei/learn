using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using Oracle.ManagedDataAccess.Client;

namespace CETGradeSelect
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {



        public MainWindow()
        {
            InitializeComponent();
        }

        //点击显示登录界面按钮
        private void ShowLogin(object sender, RoutedEventArgs e)
        {
            InputWindow.Visibility = Visibility.Hidden;
            SelectWindow.Visibility = Visibility.Hidden;
            LoginWindow.Visibility = Visibility.Visible;
        }

        //点击显示查询界面按钮
        private void ShowSelectGrate(object sender, RoutedEventArgs e)
        {
            LoginWindow.Visibility = Visibility.Hidden;
            InputWindow.Visibility = Visibility.Hidden;
            SelectWindow.Visibility = Visibility.Visible;
        }

        //点击显示录入界面按钮
        private void ShowInputGrate(object sender, RoutedEventArgs e)
        {
            LoginWindow.Visibility = Visibility.Hidden;
            SelectWindow.Visibility = Visibility.Hidden;
            InputWindow.Visibility = Visibility.Visible;
            if (userName.Text != "system" && userName.Text != "SYSTEM")
            {
                MessageBox.Show("仅有管理员可以录入", "没有权限", MessageBoxButton.OK, MessageBoxImage.Error);
                LoginWindow.Visibility = Visibility.Visible;
                InputWindow.Visibility = Visibility.Hidden;
                SelectWindow.Visibility = Visibility.Hidden;
            }
        }

        //创建数据库连接
        public OracleConnection OpenServe()
        {
            string userId, thePassword;
            string dataSource = "(DESCRIPTION = (ADDRESS = (PROTOCOL = TCP)(HOST = localhost)(PORT = 1521))(CONNECT_DATA = (SERVICE_NAME = orcl)))";
            userId = userName.Text;
            thePassword = userPassword.Password;
            string loginStr = "user id=" + userId + ";" + "password=" + thePassword + ";" + "data source=" + dataSource;
            OracleConnection conn = new OracleConnection(loginStr);

            return conn;
        }


        //点击登录界面的登录按钮
        private void ClickLogin(object sender, RoutedEventArgs e)
        {

            OracleConnection conn = OpenServe();
            try
            {
                conn.Open();
            }
            catch (Oracle.ManagedDataAccess.Client.OracleException a)
            {
                MessageBox.Show(a.ToString(), "登录错误", MessageBoxButton.OK, MessageBoxImage.Error);
                return;
            }
            MessageBox.Show("登录成功", "登录成功", MessageBoxButton.OK, MessageBoxImage.Information);
            LoginWindow.Visibility = Visibility.Hidden;
        }

        //按学号查询按钮
        private void SelectById(object sender, RoutedEventArgs e)
        {
            OracleConnection conn = OpenServe();
            try
            {
                conn.Open();
            }
            catch (Oracle.ManagedDataAccess.Client.OracleException a)
            {
                MessageBox.Show(a.ToString(), "请先登录", MessageBoxButton.OK, MessageBoxImage.Error);
                return;
            }
            OracleCommand oracleCommand = new OracleCommand(" ", conn);
            oracleCommand.CommandText = "select * from student_information where " + "StudentId=" + selectId.Text;
            OracleDataReader reader = oracleCommand.ExecuteReader();
            reader.Read();
            StudentId.Content = "学号：" + reader["studentId"].ToString();
            StudentName.Content = "姓名：" + reader["studentName"].ToString();
            StudentSex.Content = "性别：" + reader["studentSex"].ToString();
            StudentGroup.Content = "民族：" + reader["studentGroup"].ToString();
            StudentGrade.Content = "年级：" + reader["studentGrade"].ToString();
            IdentifyNum.Content = "身份证号" + reader["IdNum"];
            CollegeName.Content = "学院名称：" + reader["collegeName"].ToString();
            SubjectName.Content = "专业名称：" + reader["subjectName"].ToString();
            ExamDate.Content = "考试日期：" + reader["examDate"].ToString();
            ExamSource.Content = "考试成绩：" + reader["CETScore"].ToString();

            //查询学院表的内容
            oracleCommand.CommandText = "SELECT CollegeId from College where " + "collegeName =(select CollegeName from student_information where StudentId=" + selectId.Text + ")";
            OracleDataReader reader1 = oracleCommand.ExecuteReader();
            reader1.Read();
            CollegeId.Content = "学院编号：" + reader1["collegeId"].ToString();

            //查询专业表的内容
            oracleCommand.CommandText = "SELECT SubjectId from Subject where SubjectName=(select SubjectName from student_information where StudentId=" + selectId.Text + ")";
            OracleDataReader reader2 = oracleCommand.ExecuteReader();
            reader2.Read();
            SubjectId.Content = "专业编号：" + reader2["subjectId"].ToString();
        }

        //点击录入界面的的录入按钮
        private void ClickInputInfo(object sender, RoutedEventArgs e)
        {
            OracleConnection conn = OpenServe();
            try
            {
                conn.Open();
            }
            catch (Oracle.ManagedDataAccess.Client.OracleException a)
            {
                MessageBox.Show(a.ToString(), "请先登录", MessageBoxButton.OK, MessageBoxImage.Error);
                return;
            }
            
            string Input = "INSERT INTO student_information(StudentId,StudentName,StudentSex,StudentGroup,StudentGrade,IdNum,CollegeName,SubjectName,ExamDate,CETScore) VALUES("
              + InputStudentId.Text + ",'" + InputName.Text + "','" + InputSex.Text + "','" + InputGroup.Text + "'," + InputGrade.Text + "," + InputIdNum.Text + ",'" 
              + InputCollegeName.Text + "','" + InputSubjectName.Text + "','" + InputExamDate.Text + "'," + InputExamScore.Text + ")";
            string InputCollege = "INSERT INTO college (collegeName,collegeId) VALUES ('" + InputCollegeName.Text + "'," + InputCollegeId.Text + ")";
            string InputSubject = "INSERT INTO subject (subjectName,subjectId) VALUES ('" + InputSubjectName.Text + "'," + InputSubjectId.Text + ")";
            OracleCommand oracleCommand = new OracleCommand(Input, conn);
            oracleCommand.ExecuteNonQuery();
            OracleCommand oracleCommand1 = new OracleCommand(InputCollege, conn);
            oracleCommand1.ExecuteNonQuery();
            OracleCommand oracleCommand2 = new OracleCommand(InputSubject, conn);
            oracleCommand2.ExecuteNonQuery();
            MessageBox.Show("信息录入成功", "成功", MessageBoxButton.OK, MessageBoxImage.Information);
        }

        //点击退出按钮
        private void ClickExit(object sender, RoutedEventArgs e)
        {
            Application.Current.Shutdown();
        }

        //点击帮助按钮
        private void ClickHelp(object sender, RoutedEventArgs e)
        {
            Process.Start(@"C:\Users\Amphetamine\Desktop\readme.txt");
        }

    }
}