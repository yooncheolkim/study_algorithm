
## 9252_LCS 2_

### �Է�
> LCS(Longest Common Subsequence, ���� ���� �κ� ����)������ �� ������ �־����� ��, ����� �κ� ������ �Ǵ� ���� �� ���� �� ���� ã�� �����̴�.
���� ���, ACAYKP�� CAPCAK�� LCS�� ACAK�� �ȴ�.

> ù° �ٰ� ��° �ٿ� �� ���ڿ��� �־�����. ���ڿ��� ���ĺ� �빮�ڷθ� �̷���� ������, �ִ� 1000���ڷ� �̷���� �ִ�.
### ���
> ù° �ٿ� �Է����� �־��� �� ���ڿ��� LCS�� ���̸�, ��° �ٿ� LCS�� ����Ѵ�.
> LCS�� ���������� ��쿡�� �ƹ��ų� ����Ѵ�.

### Ǯ��
- dp�� 9251(LCS) ó�� Ǯ��..
- ����
- input1[i] == input2[j] �� ���, stack�� �ְ� i-- , j--
- input1[i] != input2[j] �� ���, (i-1,j) �� (i,j-1)�� (i,j)�� ����� �����ߴ��� Ȯ��
- ��, dp[i][j] �� ���� i,j�� �̵�
- i,j >=0 ������..