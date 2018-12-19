int getSum(int left, int right)
{
    int CF = (left & right) << 1; //保存进位信息
    left ^= right;                //保存不考虑进位的加法结果

    //上述的表达式已经计算出不考虑进位的结果，和需要进位的标志位
    //以下循环里面的都是关于结果和进位之间的计算
    //相当于之前十进制的例子，56+89，先计算不考虑进位情况的结果：35，此时CF保存的进位为110
    //给个位,十位，百位分别加上0，1，1，得出最终结果145；

    while (CF) //有进位的情况下一直检测
    {
        right = CF;
        CF = (left & right) << 1; //继续检测是否还有进位的位
        left ^= right;

        //将不考虑进位的结果与上次需进位的位相异或，得出的结果依旧没有考虑是否进位存在
        //且若此时的进位标志为0，不需要进位，则考虑不考虑是否进位都无关，所以是最终结果
        //但若是依旧存在进位标志，则继续进行上述步骤。
    }
    return left;
}