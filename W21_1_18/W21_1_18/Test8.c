#define _CRT_SECURE_NO_WARNINGS

//�������ö������ĸ��ڵ� p �� q ����дһ���������������������Ƿ���ͬ��
//
//����������ڽṹ����ͬ�����ҽڵ������ͬ��ֵ������Ϊ��������ͬ�ġ�

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/


bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
	if (p == NULL && q == NULL)
		return true;

	//�ṹ��ͬ
	if (p == NULL && q != NULL)
		return false;

	if (p != NULL && q == NULL)
		return false;

	//ֵ��ͬ
	if (p->val != q->val)
		return false;

	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}