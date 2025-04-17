```
char* array2string(int result[], int n) {
	char buf[BUFSIZ];
	int index = 0;
	for (int i = 0; i < n; i++) {
		if (is_operator2(result[i]))
			index += sprintf(&buf[index], "%c ", result[i]);
		else
			index += sprintf(&buf[index], "%d ", result[i]);
	}
	return strdup(buf);

}
```

=>sprintf(&buf[index]//현재 point print하고 그 다음으로 넘기는 항
return strdup(buf); 다이나믹 알로케이션?

```
int main(void)
{
	char expression[BUFSIZ] = "3 * 4 + 16 + 25";
	printf("%s\n", expression);
	char* postfix = infix_to_post(expression);  // 프로그램 4.8을 참조해라.
	printf("%s\n", postfix);
	//TreeNode* root = make_tree(postfix);
	int value = evaluate(root); // 프로그램 8,6을 참조해라.
	//printf("수식의 값은 %d입니다.\n", value);
	free(postfix);
	return 0;
}
```
make_tree(postfix) //작성하
