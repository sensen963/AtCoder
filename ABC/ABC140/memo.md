# memo

## C

- 最初と最後はBそのもの
- 途中iはB[i]とB[i+1]より小さい中で最大のものなのでmin(B[i],B[i+1])
- 絵をかくと上は明らか

## D

- あるR,Lではその境界でしか満足度は変わらない
    - つまり区間RL内のものはそのまま入れ替わるため満足度は変化しない
- したがっで満足度は一度の操作で0~2変化させることができる
- 全体の満足度の合計は最大N-1であるが現在の満足度がN-1より小さい場合不満足の2点を選べば良いので満足度を2上げることができる
- そのため初期満足度をSとすると一度の操作で2上げることができるのでmax(N-1,S+2K)となる

## E

- すべての組み合わせを考えるとO(N^2)なので間に合わない
- 二番目に大きくなるような区間の組み合わせを考えるようにする(頻出の考え方)
- 自分より大きいもののうち左にある2つの位置と右にある位置がわかれば組み合わせはわかる
- 実現方法は大きいものから考えてその位置をsetで管理するとすでに大きいものの中で自分の位置から近い順に考えることができる