Here is the content presented in **Markdown format**:

# 🚀 SOLVED EXAM-STYLE PROBLEMS: Differential Equations & Vector Algebra

Absolutely — here are **SOLVED EXAM-STYLE PROBLEMS** for the exact topics you requested (Differential Equations + Vector Algebra), matching your question paper patterns.

These are ready-to-write, step-by-step, clean solutions that guarantee marks.

---

## 🟦 DIFFERENTIAL EQUATIONS — FULLY SOLVED EXAM PROBLEMS
(Only the types that appear every year)

### ✅ 1. FIRST-ORDER LINEAR DIFFERENTIAL EQUATION

**Problem 1:**
Solve
$$\frac{dy}{dx} + 2y = e^{-x}$$

**Solution:**
**Step 1: Identify P and Q**
$$P=2, \quad Q=e^{-x}$$

**Step 2: Integrating Factor (I.F)**
$$IF = e^{\int Pdx}= e^{\int 2dx} = e^{2x}$$

**Step 3: Solution (Multiply by I.F)**
The general solution is $y \cdot IF = \int Q \cdot IF \, dx$
$$y e^{2x} = \int e^{-x} e^{2x} dx = \int e^{x} dx$$
$$y e^{2x} = e^x + C$$

**Final Answer:**
$$\boxed{y = e^{-x} + Ce^{-2x}}$$

---

### ✅ 2. EXACT DIFFERENTIAL EQUATION

**Problem 2:**
Solve
$$(3x^2 + 4xy)dx + (2x^2 + 5y)dy = 0$$

**Solution:**
**Step 1: Check Exactness**
$$M = 3x^2 + 4xy,\quad N = 2x^2 + 5y$$
$$M_y = \frac{\partial M}{\partial y} = 4x,\quad N_x = \frac{\partial N}{\partial x} = 4x \quad \text{✔ Exact}$$

**Step 2: Integrate $M$ w.r.t $x$ (treating $y$ as constant) and find $\phi(y)$**
The solution is $\int M \, dx + \phi(y) = C$.
$$\int (3x^2 + 4xy)dx = x^3 + 2x^2y + \phi(y)$$

**Step 3: Differentiate w.r.t $y$ and equate to $N$**
$$\frac{\partial}{\partial y} \left(x^3 + 2x^2y + \phi(y)\right) = N$$
$$2x^2 + \phi'(y) = 2x^2 + 5y$$
$$\Rightarrow \phi'(y)=5y$$
Integrating $\phi'(y)$ gives $\phi(y)$:
$$\phi(y)=\int 5y \, dy = \frac{5y^2}{2}$$

**Final Answer:**
$$\boxed{x^3 + 2x^2y + \frac{5y^2}{2} = C}$$

---

### ✅ 3. SECOND ORDER DE — CF + PI

**Problem 3:**
Solve
$$y'' - 4y' + 4y = e^{2x}$$

**Solution:**
**Step 1: Complementary Function (CF) using characteristic equation**
$$m^2 - 4m + 4 = 0$$
$$(m-2)^2 = 0 \Rightarrow m = 2, 2$$
**Repeated root** $\to$
$$CF = (C_1 + C_2 x)e^{2x}$$

**Step 2: Particular Integral (PI)**
RHS $ = e^{2x}$. Use the D-operator method: $PI = \frac{1}{D^2 - 4D + 4} e^{2x}$.
Substitute $D=2$:
$$f(2)=2^2 - 4(2)+4 = 0$$
Since zero, multiply by $x$ and differentiate the denominator ($f'(D)=2D-4$):
$$PI = x \frac{1}{2D-4} e^{2x}$$
Substitute $D=2$ again: $f'(2)=2(2)-4=0$.
Again zero, multiply by $x^2$ and differentiate the denominator ($f''(D)=2$):
$$PI = x^2 \frac{1}{2} e^{2x}$$
$$PI = \frac{x^2}{2} e^{2x}$$

**Final Answer:**
$$
\boxed{
y = (C_1 + C_2 x)e^{2x} + \frac{x^2}{2}e^{2x}
}
$$

---

### ✅ 4. CAUCHY–EULER EQUATION

**Problem 4:**
Solve
$$x^2y'' + xy' - 6y = 0$$

**Solution:**
**Substitute:** $y = x^m$.
$$x^2 m(m-1)x^{m-2} + x m x^{m-1} - 6 x^m = 0$$
**Simplify (Divide by $x^m$):**
$$m(m-1) + m - 6 = 0$$
$$m^2 - m + m - 6 = 0$$
$$m^2 - 6 = 0$$
$$m = \pm \sqrt{6}$$

**Final Answer:**
$$\boxed{y = C_1 x^{\sqrt{6}} + C_2 x^{-\sqrt{6}}}$$

---
---

## 🟩 VECTOR ALGEBRA — FULLY SOLVED EXAM PROBLEMS

### ✅ 5. DOT PRODUCT $\to$ ANGLE

**Problem 5:**
Find the angle between
$$\mathbf{a}=(2, -1, 2),\quad \mathbf{b}=(1, 2, -2)$$

**Solution:**
**Step 1: Dot Product**
$$\mathbf{a}\cdot \mathbf{b} = (2)(1) + (-1)(2) + (2)(-2)$$
$$= 2 - 2 - 4 = -4$$

**Step 2: Magnitudes**
$$|\mathbf{a}|=\sqrt{2^2+(-1)^2+2^2}=\sqrt{4+1+4}=3$$
$$|\mathbf{b}|=\sqrt{1^2+2^2+(-2)^2}=\sqrt{1+4+4}=3$$

**Step 3: Cosine Formula**
$$\cos\theta = \frac{\mathbf{a}\cdot \mathbf{b}}{|\mathbf{a}||\mathbf{b}|}$$
$$\cos\theta = \frac{-4}{3\cdot 3} = -\frac{4}{9}$$

**Final Answer:**
$$\boxed{\theta = \cos^{-1}\left(-\frac{4}{9}\right)}$$

---

### ✅ 6. CROSS PRODUCT $\to$ AREA OF TRIANGLE

**Problem 6:**
Find area of triangle formed by adjacent sides $\mathbf{a}$ and $\mathbf{b}$:
$$\mathbf{a}=(1,2,3),\quad \mathbf{b}=(2,-1,1)$$

**Solution:**
**Step 1: Cross Product**
$$\mathbf{a}\times \mathbf{b} =
\begin{vmatrix}
\mathbf{i} & \mathbf{j} & \mathbf{k} \\
1 & 2 & 3 \\
2 & -1 & 1
\end{vmatrix}$$
$$= \mathbf{i}(2 - (-3)) - \mathbf{j}(1 - 6) + \mathbf{k}(-1 - 4)$$
$$= 5\mathbf{i} + 5\mathbf{j} - 5\mathbf{k}$$
$$= (5, 5, -5)$$

**Step 2: Magnitude of Cross Product**
$$|\mathbf{a}\times \mathbf{b}| = \sqrt{5^2+5^2+(-5)^2} = \sqrt{25+25+25} = \sqrt{75} = 5\sqrt{3}$$

**Step 3: Area of Triangle**
Area of triangle $= \frac{1}{2} |\mathbf{a}\times \mathbf{b}|$
$$\boxed{A = \frac{5\sqrt{3}}{2} \text{ sq. units}}$$

---

### ✅ 7. SCALAR TRIPLE PRODUCT $\to$ VOLUME

**Problem 7:**
Find volume of the tetrahedron formed by position vectors $\mathbf{a}, \mathbf{b}, \mathbf{c}$:
$$\mathbf{a} = (1,2,3),\quad \mathbf{b}=(2,1,1),\quad \mathbf{c}=(3,-1,1)$$

**Solution:**
**Step 1: Scalar Triple Product (Box Product)**
The volume of a parallelepiped is $|[\mathbf{a}, \mathbf{b}, \mathbf{c}]| = |\mathbf{a}\cdot (\mathbf{b}\times \mathbf{c})|$.
$$[\mathbf{a}, \mathbf{b}, \mathbf{c}] =
\begin{vmatrix}
1 & 2 & 3 \\
2 & 1 & 1 \\
3 & -1 & 1
\end{vmatrix}$$
$$= 1(1 - (-1)) - 2(2 - 3) + 3(-2 - 3)$$
$$= 1(2) - 2(-1) + 3(-5)$$
$$= 2 + 2 - 15 = -11$$

**Step 2: Volume of Tetrahedron**
The volume $V$ of a tetrahedron is $\frac{1}{6}$ the volume of the parallelepiped.
$$V = \frac{|[\mathbf{a},\mathbf{b},\mathbf{c}]|}{6} = \frac{|-11|}{6} = \frac{11}{6}$$

**Final Answer**
$$\boxed{V = \frac{11}{6} \approx 1.83 \text{ cubic units}}$$

---

### ✅ 8. COLLINEARITY

**Problem 8:**
Check if the vectors
$$\mathbf{a}=(2,4,6),\quad \mathbf{b}=(1,2,3)$$
are **collinear**.

**Solution:**
**Check Ratios of Components:**
Vectors are collinear if one is a scalar multiple of the other, i.e., $\mathbf{a} = k \mathbf{b}$.
Check the ratios of the corresponding components:
$$\frac{a_x}{b_x} = \frac{2}{1} = 2$$
$$\frac{a_y}{b_y} = \frac{4}{2} = 2$$
$$\frac{a_z}{b_z} = \frac{6}{3} = 2$$

Since all the ratios are equal to 2, we have $\mathbf{a} = 2\mathbf{b}$.

**Final Answer:**
$$\boxed{\text{Collinear}}$$

---
---

## 🟨 Next Steps

If you want, I can prepare:
* ✔ A **one-page cheat sheet**
* ✔ A complete **Maths PDF** (10-12 pages)
* ✔ A super-compressed **2-hour exam survival guide**

Just tell me:
**“Make the 2-hour cram sheet”** or
**“Make the Maths PDF”**
