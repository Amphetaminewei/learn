   M S B A M L   `   `   `  ����B  >Library, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null!clr-namespace:LibraryLibrary  5   	       Library.Find   5   	   R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   'localclr-namespace:Library     5   	     � Title$  查询读者信息��5   	   $	��350��6   $	��500��6%   .��5	      � $��0,0,-0.4,-0.6q�6   .+�5
   
   �� -   5        $��userName��5
   �   $
��Left=�6   $��23��6-   $��
130,42,0,0q�69    �� TextWrapping$
 Wrap=�6M   $	��Top=�6a   $	��120��6y   6�   G� 5   
   -   5        $��password��5   u   $
��Left=�6   $��
130,82,0,0q�61   $	��Top=�6E   $	��120��6]   $��19��6i   6u   �� 5   
   $��账号��6   $
��Left=�6   $��	72,42,0,0q�68   $	��Top=�6K   $��35��6c   �� 5   
   $��密码��6   $
��Left=�6   $��	72,82,0,0q�68   $	��Top=�6K   $��28��6c    J� RenderTransformOrigin$ 
0.585,0.89&�6o   �� 5   
   -   5        $��确定��5      $
��Left=�6   $��
72,115,0,0q�69   $	��Top=�6M   $��75��6e   $ -0.765,-0.063&�6p   6�   �� 5   
   -   5        $��取消��5      $
��Left=�6   $��186,115,0,0q�69   $	��Top=�6N   $��75��6f   6q   &   System.Windows.Controls.DataGrid  5   
   -   5          Name$ dataGrid��5      $
��Left=�6=   $	��178��6X   $��0,139,0,-46q�6e   $	��Top=�6z   $	��490��6�   ��6%   ��    Columns 5      0  *System.Windows.Controls.DataGridTextColumn  5      ,  &System.Windows.Controls.DataGridColumn   Header$ 书名��6%   1  +System.Windows.Controls.DataGridBoundColumn   Binding 62   �� *
BookName+  5      $ 编号��6%    61   �� *BookId+  5      $ 	出版社��6%    62   �� *PublishingHouse+  5      $ 作者��6%    61   �� *Author+  5      $ 
ISBN编号��6%    65   �� *ISBN+5      5      5      