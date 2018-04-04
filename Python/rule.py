文档作者：

QCQ(秦传庆)

文档作者联系方式：

e-mail:qinchuanqing918@163.com
qq:786160313

文档书写时间：

2014-8-7

文档修订记录：

文档修订人   文档修订时间      文档修订内容
    QCQ    2014年08月08日      增加了代码编写工具内容，即第４条以及文档注意部分。 

文档补充者：

文档补充者联系方式：

文档编写目的：

１、方便程序编写者之间的交流以及相互阅读排错，特制定此文档。
２、控制代码的质量。
３、蛋白质结构预测领域算法编写的持续稳定发展。

文档主题：

    本文档规范Python代码的书写规范，对相应的细节进行规定，希望师弟们在学习Python语言的过程中予以遵守并严格执行，欢迎各位师弟对
本文档没有涉及到的地方予以补充说明。
          
文档参考文献：

序号  作者          文献    
 1    林锐  《高质量 C++/C 编程指南》

文档内容：

１、整个程序文件开头部分说明。
    需要包括程序创建时间，程序的编写者，程序的主要功能描述，程序修改记录（包括修改人、修改原因、修改时间）。
　　必须包括的项目——程序创建时间／程序编写者／程序功能描述／程序修改记录。

　　示例如下：
    '''
    Created on 2014-5-5

    @author: qcq
    acquired help from: cxp

    The description of this file:
        #English#
            The reason to write this file, what contains in this file. What is the most import function in this file or 
        what specific algorithm implemented in this file's code.
        
        N: The important common parameters should　list here.
        
        #Chinese#
        　　编写此文件的原因，在本文件里面包含一些什么。这个文件中最重要的功能是什么或者说这个文件中的代码实现了什么具体算法。
                 
        N: 本文件中重要的共有参数可以列写在此处。
        

    The change records:
            Time     Changed By    Reason
        2014/5/17        QCQ        To fix what specific problem
        2014/5/23        QCQ        To add what specific problem
        ...              ...        ...
    '''
    
    备注：英文的说明不是必须，但是考虑到有时候会出现编码上的问题，导致中文会变成乱码。因此，建议使用英文。
    
２、Python变量命名。
    关于变量的命名再林锐《高质量 C++/C 编程指南》文档中提到微软公司的“匈牙利”命名法，并建议标识符也就是变量的命名和操作系统的风
    格应当契合。具体的操作方式见此文档，为了便于快速掌握，统一风格如下：
    (1) 标识符应当直观且可以拼读,可望文知意,不必进行“解码”。
        简单来说就是变量的命名应该使用有相应具体意义的英文单词，不要简单的使用a,b,c等作为变量的名字，除非迫不得已。可以便于记忆
        和阅读，除此之外禁止使用彪悍的汉语拼音来作为变量的名字，难于理解并且增加后期的维护难度。
    (2) 标识符的长度应当符合“min-length && max-information”原则。
        标识符尽可能的短，但是需要包含尽可能全的信息。比如currentValue相较于nowValue更易于理解。
    (3) 变量的名字应当使用“名词”或者“形容词+名词”，函数的名字应当使用“动词”或者“动词+名词”（体现行为）。
    (4) 尽量避免名字中出现数字编号,如 Value1,Value2 等,除非逻辑上的确需要编号。
        这是在编程过程中最常遇到的问题，这种编程风格编写很容易，但是不利于别人甚至自身的阅读。
    (5) 类名以及非类成员函数名用大写字母开头的单词组合而成，类的成员函数名用小写字母开头的单词组合而成。
        class Picture：
            def drawPicture():
        
        def DrawPicture(value):
    (6) 变量和参数用小写字母单词组合而成，中间可加入下划线。
        value
        currentvalue或者current_value
    (7) 常量全用大写的字母,用下划线分割单词。
        MAX
        MAX_LENGTH
    (8) 如果代码行中的运算符比较多,用括号确定表达式的操作顺序,避免使用默认的优先级。
        原因在于语言运算符的优先级程序员一般记不住，为了防止出错，在相应的位置使用括号来界定优先级，这样也可以方便别人阅读代码。
    (9) 尽量不要编写太复杂的复合表达式。
        原因在于这会增加理解的难度，并且更加容易出错，因此建议每一行程序代码实现单一功能。
    (10) 在每个类声明之后、每个函数定义结束之后都要加空行。
         在一个函数体内,逻揖上密切相关的语句之间不加空行,其它地方应加空行分隔。
         原因在于不仅增加美观性，也可以增加可读性。
    (11) 一行代码只做一件事情,如只定义一个变量,或只写一条语句。这样的代码容易阅读,并且方便于写注释。
         if、for、while、do 等语句自占一行,执行语句不得紧跟其后。
         尽可能在定义变量的同时初始化该变量(就近原则)。
         Python语言使用缩进来表示代码的组织框架，规定缩进４个空格，（具体实现可以将 Tab键在相应的编辑器里面改成４个字符并且使用
         空格替代）。
    (12) 相应关键字之后要留空格。如for　if等.
         函数名之后不要留空格,紧跟左括号‘（’,以与关键字区别。
         ‘（’向后紧跟，‘）’、‘，’向前紧跟，向前紧跟,紧跟处不留空格，逗号‘，’之后要留空格。
         def Draw(self, value):
         赋值操作符、比较操作符、算术操作符、逻辑操作符、位域操作符,如“=” “+=” “>=” “<=” “+” “*” “%” “&&” “||” “<<”,“^”等二
         元操作符的前后应当加空格。
         一元操作符如“!”等前后不加空格。
         象“[]” “.”这类操作符前后不加空格。
    (13) 代码行不要过长,否则眼睛看不过来,也不便于打印。
         长表达式要在低优先级操作符处拆分成新行,操作符放在新行之首(以便突出操作符)。拆分出的新行要进行适当的缩进,使排版整齐,语
         句可读。
    (14) if 0 == currentValue:相较于if currentValue == 0更好，可以防止出现误用等号的错误。
        
３、Python程序注释。
    Python程序注释是一个宽泛的概念。从代码的规模上来说可以分成五个类别，文件首的说明也就是第一点算是一部分，其余四个部分包括如下
    
    (1) 类注释
    
        使用文档字符串进行注释，注释内容包括类说明、类内的方法说明。
        示例如下：
        class Tree:
        """ 
        description:
            Generic n-ary tree node object

            Children are additive; no provision for deleting them.
            The birth order of children is recorded: 0 for the first
            child added, 1 for the second, and so on.

        functions:
            .__init__       Constructor.
            .parent         If this is the root node, None, otherwise
                            the parent's Tree object.
            .childList      List of children, zero or more Tree objects.
            .value          Value passed to constructor; can be any type.
            .birthOrder     If this is the root node, 0, otherwise the
                            index of this child in the parent's .childList
            .nChildren()    Returns the number of self's children.
            .nthChild(n)    Returns the nth child; raises IndexError if
                            n is not a valid child number.
            .fullPath():    Returns path to self as a list of child numbers.
            .nodeId():      Returns path to self as a NodeId.
        """
    
    (2) 方法注释（包括成员函数方法和普通函数方法）
    
        使用文档字符串进行注释，注释内容包括方法说明、方法形参说明、返回值说明。
        示例如下（普通函数）：
        def ConditionOne(matrix):
        '''
        description:
            This function used for computing whether matrix comply to the Condition One.
        
        parameters:
            matrix: the input matrix, which should be a squre matrix (N + 1) * (N + 2).
            
        return:
            boolean: if matrix comply to Condition One, then return True, otherwise False.
        '''
    
    (3) 代码功能块注释
    
        使用特殊的格式对即将出现的代码块进行说明，包括功能以及修改或者编程思路。
        示例如下：
        #===========================================================================
        # new code, added after
        # ...
        #===========================================================================
        #get the diagonal items to form a vector
        diagonal_vector = np.mat(matrix.diagonal())
        value_list = []
        for item in range(max(diagonal_vector.shape)):
            value_list.append(convertedusr_vector[0, item] / diagonal_vector[0, item])
        
    (4) 代码行注释
    
        使用#对下边紧跟的代码行进行注释。
        示例如下：
        #initial the convertedusr_vector to 1 * (len(usr) + 1)
        convertedusr_vector = np.zeros((1, len(usr) + 1))    

４、代码编写工具。
    考虑到Python代码的编辑器很多，为了统一代码的编写环境，现建议如下编写工具。
    
    (1) Python解释器的版本是2.7版本，不建议使用最新版本，这是考虑到和我们所使用的PyRosetta包有关系，对应的是官方2.7版本的API
        文档。 API文档是主要的编程查询资料。
    (2) ipython相较于Python直接提供的命令行工具是一个可交互的命令行工具，可以使用这个工具辅助代码的编写。注意和Python版本的依
        赖性关系。
    (3) eclipse是一个跨平台的集成编译器，可以通过安装PyDev插件的方式实现编写以及运行Python的功能，并且eclipse提供自动补全功能
        ，并且可以跨平台使用，为后期可能存在的向Linux平台移植作准备。
    (4) IDLE是Python解释器默认提供的文本编辑器，可以方便使用。
    (5) 可替代的文本编辑器是gedit，本文本编辑器是Linux操作系统上默认的文本编辑器，现在也有Windows版本，不管怎么样，本人十分喜
        欢。
    (6) 使用坚果云软件来实现小组成员之间资料的共享，本软件可以跨平台使用，缺点是免费版本有每月的流量使用限制。
    (7) 使用奇虎360云盘来存储大剂量的个人文件资料，也可以实现文件之间的共享，缺点不能实时实现文件的快速共享，不支持多人多账户登
        陆，但是优点是容量大。
    (8) 关于本领域的变成可能需要使用Python的第三方包，数据输出的图像文件的绘制使用matplotlab包，关于数学的相关运算包numpy，这
        些地三方包需要额外学习使用。最主要的第三方包就是PyRosetta。
    
    需要注意的是使用以上的编辑器包括IDLE、eclipse、gedit，一定要将缩进的方式改成Tab按键是４个字符，并且使用空格予以替换，相应
    的具体设置请参照具体的编辑器。

文档注意：
    
＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#本文档的编写时间仓促，因此难免出现纰漏，建议阅读过此文档的同仁给予建议。
#本文档的编写者水平有限，因此难免出现纰漏，建议阅读过此文档的同仁给予建议。
#本文档的内容比较粗略，因此如果需要详细信息请参考本文档列出的参考文献。
#本文档的内容尽管粗鄙，但是生物信息学的蛋白质结构预测算法团队的成员均务必遵守本文档提出的规则。
#本文档的提出晚于本人算法的编写，因此前期编写的代码可能不是很符合规范，望大家阅读的时候给予特别注意。
#
#如果阅读者感觉本文档编写十分出色，请向秦传庆的工商账户进行捐助，秦传庆本人不甚感激。
#最后祝大家在生物信息学这个巨大的海洋里尽情的畅游和玩耍，并取得丰硕的成果。为祖国的繁荣昌盛做贡献，为中华名族的伟大复兴而高兴的
#读书。
＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝

文档版权声明：

    本文档是由秦传庆同学主力完成，不过可以随意派发和修改，但是务必点出秦传庆同学所作贡献，秦传庆对此十分感谢。

