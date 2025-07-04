Варіант 2 (Піраміда з основою правильного 4-кутника; Наближення/віддалення; Клавіші ← →)

1.
В ініціалізації:
glClearColor(): Встановлює колір, яким буде очищено екран.
glClearDepth(): Встановлює значення для очищення буфера глибини.
glEnable(GL_DEPTH_TEST): Вмикає тест глибини, що дозволяє коректно відображати 3D-об'єкти.
glDepthFunc(): Встановлює умову, за якою проходить тест глибини.
glShadeModel(GL_SMOOTH): Вмикає режим плавного зафарбовування, де кольори між вершинами градієнтно переходять один в одного.
glHint(): Надає "підказку" реалізації OpenGL щодо якості виконання певних операцій.
У малюванні сцени:
glClear(): Очищує буфери, вказані у параметрах.
glMatrixMode(): Визначає, з якою матрицею (проекції, моделі-виду) будуть працювати наступні функції трансформації.
glLoadIdentity(): Замінює поточну матрицю на одиничну, фактично "скидаючи" всі попередні трансформації (обертання, зсуви, масштабування).
glTranslatef(): Зміщує систему координат, а разом з нею і об'єкт, вздовж осей X, Y, Z. Використовується для наближення/віддалення камери.
glRotatef(): Обертає систему координат навколо заданого вектора (осі) на вказаний кут. Використовується для обертання фігури мишею.
glBegin() / glEnd(): Визначають початок і кінець списку вершин для малювання примітивів (квадратів, трикутників).
glColor3f(): Встановлює поточний колір для малювання наступних вершин.
glVertex3f(): Визначає координати вершини (точки) у 3D-просторі.
glViewport(): Встановлює область для малювання всередині вікна. Зазвичай займає все вікно.

2. 
glutDisplayFunc(displayScene): Реєструє функцію displayScene як основну функцію малювання. Вона викликається щоразу, коли GLUT вирішує, що вікно потрібно перемалювати.
glutReshapeFunc(reshapeWindow): Реєструє функцію reshapeWindow, яка викликається при створенні вікна та при кожній зміні його розмірів.
glutMouseFunc(handleMouseClick): Реєструє функцію handleMouseClick, яка реагує на натискання та відпускання кнопок миші.
glutMotionFunc(handleMouseMove): Реєструє handleMouseMove. Ця функція викликається, коли користувач рухає мишею із затиснутою кнопкою.
glutSpecialFunc(handleSpecialKeys): Реєструє handleSpecialKeys для обробки натискань спеціальних клавіш (стрілки, F1–F12 тощо).
glutKeyboardFunc(handleKeyboard): Реєструє handleKeyboard для обробки натискань звичайних клавіш (літери, цифри, Esc).

3.
glutIdleFunc(): Реєструє функцію, яка викликається постійно, коли немає жодних інших подій для обробки.
glutPassiveMotionFunc():Викликається, коли користувач рухає мишею без затиснутої кнопки.
glutTimerFunc(): Реєструє функцію, яка буде викликана один раз через вказану кількість мілісекунд. Для постійної анімації її потрібно "перереєстровувати" всередині самої себе.
glutEntryFunc(): Викликається, коли курсор миші входить у вікно або залишає його межі.
glutVisibilityFunc(): Дозволяє відстежувати, чи є вікно повністю або частково видимим на екрані.
glutWindowStatusFunc(): Викликається, коли вікно змінює свій стан.
