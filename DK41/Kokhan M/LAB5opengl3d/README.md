Відповіді на питання
Варіант 7

1. Які функції для роботи безпосередньо з OpenGL ви імплементували? Коротко опишіть їхнє призначення.

У коді використано такі основні функції OpenGL (префікс gl):

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT): Очищає вказані буфери. GL_COLOR_BUFFER_BIT очищає колірний буфер (малює фон), а GL_DEPTH_BUFFER_BIT очищає буфер глибини, що необхідно для коректного відображення 3D-об'єктів (щоб об'єкти, які далі, не перекривали ті, що ближче).

glMatrixMode(GLenum mode): Встановлює поточну матрицю, над якою будуть виконуватися подальші операції. Використовуються режими GL_MODELVIEW (для трансформацій об'єктів та камери) та GL_PROJECTION (для налаштування проекції - перспективи чи ортогональної).

glLoadIdentity(): Замінює поточну матрицю на одиничну. Це скидає всі попередні трансформації для поточної матриці.

glTranslatef(GLfloat x, GLfloat y, GLfloat z): Множить поточну матрицю на матрицю перенесення (трансляції). Використовується для зміни положення об'єктів або "камери".

glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z): Множить поточну матрицю на матрицю обертання. Використовується для обертання об'єктів або сцени навколо вказаної осі на заданий кут.

glEnable(GLenum cap): Вмикає певну можливість OpenGL. У коді використовується glEnable(GL_DEPTH_TEST) для ввімкнення тесту глибини, що дозволяє коректно відображати 3D-об'єкти з урахуванням їхньої віддаленості від спостерігача.

glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha): Встановлює колір, яким буде очищатися колірний буфер під час наступного виклику glClear(GL_COLOR_BUFFER_BIT).

glColor3fv(const GLfloat *v): Встановлює поточний колір для малювання наступних примітивів, використовуючи масив з трьох компонентів (RGB).

glBegin(GLenum mode): Розпочинає визначення нового примітиву (набору вершин). mode вказує тип примітиву, наприклад, GL_POLYGON (для довільного багатокутника) або GL_QUADS (для набору чотирикутників).

glVertex3fv(const GLfloat *v): Визначає вершину поточного примітиву, використовуючи масив з трьох компонентів (X, Y, Z).

glEnd(): Завершує визначення поточного примітиву.

glViewport(GLint x, GLint y, GLsizei width, GLsizei height): Визначає область у вікні (у пікселях), куди буде відображатися результат рендерингу. Зазвичай встановлюється на весь розмір вікна.

Також використовується функція з бібліотеки GLU (Graphics Library Utility), яка часто йде в комплекті з OpenGL:

gluPerspective(GLdouble fovy, GLdouble aspect, GLdouble zNear, GLdouble zFar): Створює перспективну матрицю проекції. Встановлює "камеру" з певним кутом огляду по вертикалі (fovy), співвідношенням сторін вікна (aspect), а також ближньою (zNear) та дальньою (zFar) площинами відсікання.

2. Які функції реєстрації зворотних викликів ви використовували? Коротко опишіть їхнє призначення.

У коді використано такі функції реєстрації зворотних викликів з бібліотеки GLUT/freeglut (префікс glut...Func):

glutDisplayFunc(void (*func)(void)): Реєструє функцію (display), яка буде викликатися щоразу, коли вікно потребує перемалювання. Це головна функція, де відбувається весь рендеринг сцени.

glutReshapeFunc(void (*func)(int width, int height)): Реєструє функцію (reshape), яка викликається при зміні розміру вікна. Використовується для налаштування viewport та матриці проекції відповідно до нових розмірів вікна.

glutIdleFunc(void (*func)(void)): Реєструє функцію (idle), яка викликається, коли програма не виконує інших подій (наприклад, очікує введення користувача). Використовується для виконання фонових завдань, таких як оновлення стану для анімації.

3. Які існують інші функції обробки подій (зміна розміру вікна, введення інформації від користувача)? Коротко опишіть їхнє призначення.

GLUT/freeglut надає широкий набір функцій для обробки різних подій користувача та системних подій, окрім вже згаданих display та reshape. Ось деякі з них:

Введення з клавіатури:

glutKeyboardFunc(void (*func)(unsigned char key, int x, int y)): Реєструє функцію для обробки натискань звичайних клавіш (літери, цифри, символи).

glutSpecialFunc(void (*func)(int key, int x, int int y)): Реєструє функцію для обробки натискань спеціальних клавіш (стрілки, F1-F12, Page Up/Down, Home/End тощо).

Введення миші:

glutMouseFunc(void (*func)(int button, int state, int x, int y)): Реєструє функцію для обробки подій натискання/відпускання кнопок миші.

glutMotionFunc(void (*func)(int x, int y)): Реєструє функцію для обробки подій руху миші при натиснутій кнопці (drag).

glutPassiveMotionFunc(void (*func)(int x, int int y)): Реєструє функцію для обробки подій руху миші без натиснутих кнопок.

Події вікна:

glutEntryFunc(void (*func)(int state)): Реєструє функцію, яка викликається, коли курсор миші входить у вікно або виходить з нього.

glutVisibilityFunc(void (*func)(int state)): Реєструє функцію, яка викликається при зміні видимості вікна (наприклад, згортання/розгортання, перекриття іншим вікном).

glutCloseFunc(void (*func)(void)): Реєструє функцію, яка викликається перед закриттям вікна.

Таймери:

glutTimerFunc(unsigned int millis, void (*func)(int value), int value): Реєструє функцію, яка буде викликана один раз через задану кількість мілісекунд. Часто використовується для анімації або планування подій.

Система меню:

glutCreateMenu(void (*func)(int value)): Створює контекстне меню та реєструє функцію, яка викликається при виборі пункту меню.

glutAddMenuEntry(char *label, int value): Додає пункт до поточного меню.

glutAttachMenu(int button): Прив'язує поточне меню до кнопки миші.
