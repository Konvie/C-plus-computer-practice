### 第4题：设计一个保留字（或关键字）的统计程序

- 建立保留字文件；

- 从源数据文件（C或C++语言程序）中，读取字符或字符串，与保留字文件中的保留字进行匹配比较，并统计计数。

- 输出两张表文件：保留字计数，扫描程序的次数，非保留字计数。

### 第5题：设计一个文本行编辑程序

l 对文本文件按行进行编辑：先从输入文件中读取数据，然后根据行编辑命令处理，将结果写到输出文件中。

l 行编辑命令包括：

| **序号** | **行编辑命令格式**          | **功能**                           |
| -------- | --------------------------- | ---------------------------------- |
| **１**   | ***L m，n**                 | **显示从第m至n行的文本**           |
| **２**   | ***I m**  **……**  **^Z**    | **插入文本（……）在第m行后**        |
| **３**   | ***D m，n**                 | **删除从第m至n行的文本**           |
| **４**   | ***R m，n**  **……**  **^Z** | **用文本（……）替换第m至n行的文本** |
| **５**   | ***X**                      | **保存并退出编辑程序**             |
| **６**   | ***Q**                      | **放弃并退出程序**                 |

