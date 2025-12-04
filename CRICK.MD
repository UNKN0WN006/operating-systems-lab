# ✅ **MATHS FOR IT–I — DIFFERENTIAL EQUATIONS (Exam-Focused Notes)**

Your past papers show these patterns:

### ✔️ 1. First-Order Linear DE
### ✔️ 2. Exact / Non-exact DE
### ✔️ 3. Higher-Order Linear DE with Constant Coefficients
### ✔️ 4. Complementary Function (CF) + Particular Integral (PI)
### ✔️ 5. Method of Undetermined Coefficients
### ✔️ 6. Cauchy–Euler DE
### ✔️ 7. Systems of Differential Equations (easy ones)
### ✔️ 8. Differential Equation Formation

I will give you crisp formulas + examples.

---

# ⭐ PART A — FIRST-ORDER DIFFERENTIAL EQUATIONS

## 🔹 **1. Linear Differential Equation**

Standard form:
$$\frac{dy}{dx} + Py = Q$$

**Integrating Factor (I.F):**
$$IF = e^{\int Pdx}$$

**Solution:**
$$y \cdot IF = \int Q \cdot IF \, dx + C$$

### **Example (similar to past paper):**

Solve:
$$\frac{dy}{dx} + 3y = e^{2x}$$

**Solution:**

* **P = 3**
* **Q = e^{2x}**

$$IF = e^{\int 3 dx} = e^{3x}$$

$$y e^{3x} = \int e^{2x} e^{3x} dx = \int e^{5x} dx = \frac{e^{5x}}{5} + C$$

$$\boxed{y = \frac{e^{2x}}{5} + C e^{-3x}}$$

---

## 🔹 **2. Exact Differential Equation**

Standard:
$$M(x,y)dx + N(x,y)dy = 0$$

**Check Exactness:**
$$\frac{\partial M}{\partial y} = \frac{\partial N}{\partial x}$$

If exact $\to$ **Solution:** $\int M \, dx + \int (\text{terms in } N \text{ independent of } x) \, dy = C$

### Example:

$$(2xy + 3)dx + (x^2 + 4y)dy = 0$$

**Check:**
$$M_y = 2x,\quad N_x = 2x \quad \text{✔ Exact}$$

**Integrate $M$ w.r.t $x$:**
$$\int (2xy + 3) dx = x^2 y + 3x + \phi(y)$$

**Differentiate w.r.t $y$ and equate to $N$** (to find $\phi(y)$):
$$x^2 + \phi'(y) = x^2 + 4y$$
$$\Rightarrow \phi'(y) = 4y$$
$$\phi(y) = 2y^2$$

**Final solution:**
$$\boxed{x^2 y + 3x + 2y^2 = C}$$

---

# ⭐ PART B — HIGHER ORDER LINEAR DEs (MOST IMPORTANT)

## 🔸 Standard form:
$$a\frac{d^ny}{dx^n} + b\frac{d^{n-1}y}{dx^{n-1}} + \dots + ky = f(x)$$

Solve using:

1. **Complementary Function (CF)**
2. **Particular Integral (PI)**

---

## 🔹 **CF — Characteristic Equation Method**

**Example (Distinct Real Roots):**
$$y'' - 5y' + 6y = 0$$

Characteristic equation:
$$m^2 - 5m + 6 = 0 \Rightarrow (m-2)(m-3)=0$$

$$\boxed{CF = C_1 e^{2x} + C_2 e^{3x}}$$

---

## 🔹 **PI Based on RHS**

### **Case 1: $f(x)=e^{ax}$**

$$PI = \frac{e^{ax}}{f(a)}$$

**Example (Failure Case):**
$$(y'' - 3y' + 2y = e^{x})$$

$$f(m)=m^2-3m+2 \Rightarrow f(1)=1-3+2=0$$

**Since zero $\to$ multiply by $x$ and differentiate denominator ($f'(m)=2m-3$):**
$$PI = x \frac{e^x}{f'(1)} = x \frac{e^x}{2(1)-3} = x \frac{e^x}{-1} = -x e^x$$

---

### **Case 2: $f(x)=\sin ax$ or $\cos ax$**

Substitute $D^2$ with $-a^2$ in the denominator $f(D)$:
$$PI = \frac{\sin ax}{f(-a^2)}\quad\text{or}\quad \frac{\cos ax}{f(-a^2)}$$

**Example (Failure Case):**
$$y'' + 9y = \sin 3x$$
$$f(D)=D^2+9 \Rightarrow f(-3^2)=-9+9=0$$

**Failure $\to$ use the special rule $\frac{1}{D^2+a^2} \sin ax = -\frac{x}{2a} \cos ax$:**
$$PI = -\frac{x}{2(3)}\cos 3x = -\frac{x}{6}\cos 3x$$

---

### **Case 3: Polynomial RHS ($f(x)=x^n$)**

**Example:**
$$y'' - y = 6x$$

Assume **$PI = Ax + B$** (since RHS is degree 1).
$$y' = A, \quad y'' = 0$$
Substitute into DE: $0 - (Ax + B) = 6x \implies -Ax - B = 6x$
Equating coefficients: $-A=6 \implies A=-6$; $-B=0 \implies B=0$.
$$PI = -6x$$

---

### ✔ **Final Answer form:**
The complete solution is $y = CF + PI$.
$$\boxed{y = CF + PI}$$

---

# ⭐ PART C — CAUCHY–EULER EQUATION

**Form:**
$$x^2 y'' + axy' + by = f(x)$$

**Shortcut Substitution:** $x = e^z$ or **$y = x^m$** (for homogeneous case $f(x)=0$).

**Example:**
$$x^2 y'' + x y' - 6y = 0$$

**Characteristic Equation using $y=x^m$:**
$$m(m-1)+m-6=0$$
$$\Rightarrow m^2-m+m-6=0$$
$$\Rightarrow m^2-6=0 \Rightarrow m = \pm\sqrt{6}$$

$$\boxed{y = C_1 x^{\sqrt{6}} + C_2 x^{-\sqrt{6}}}$$

---

# ⭐ PART D — SYSTEMS OF DIFFERENTIAL EQUATIONS

Typical question:
Solve:
$$\frac{dx}{dt} = 3x + 4y, \quad \frac{dy}{dt} = -4x + 3y$$

**Method: Eigenvalue Method** (characteristic equation from coefficient matrix $\begin{pmatrix} 3 & 4 \\ -4 & 3 \end{pmatrix}$)
$$|A - \lambda I| = 0 \Rightarrow (3-\lambda)^2 + 16 = 0 \Rightarrow \lambda = 3 \pm 4i$$

**Solution Format (Complex Conjugate Roots $\alpha \pm i\beta$):**
$$\alpha=3, \quad \beta=4$$
$$x = e^{3t}(C_1 \cos 4t + C_2 \sin 4t)$$
$$y = e^{3t}(C_1 \sin 4t - C_2 \cos 4t)$$
(Note: $y$ is found by substituting $x$ and its derivative into one of the original DEs, then simplifying.)

---

# 🔥 DIFFERENTIAL EQUATION QUICK LAST-MINUTE BOX

* **First order linear** $\to$ **I.F method**
* **Exact** $\to$ **$M_y=N_x$**
* **CF** $\to$ Roots of characteristic eq.
* **PI** $\to$ Based on RHS (use shortcut table: $\frac{1}{f(D)}f(x)$)
* **Cauchy–Euler** $\to$ **$y=x^m$**
* **System of DE** $\to$ Eigenvalue method

---

# ✅ **VECTOR ALGEBRA (Exam-Focused Notes)**

Matches exactly the pattern in your past papers.

Your papers mainly ask:

1. Dot & Cross product
2. Scalar triple product (STP)
3. Vector triple product
4. Collinearity & Coplanarity
5. Area & Volume
6. Vector equation of lines/planes

Let’s cover them.

---

# ⭐ PART A — BASIC OPERATIONS

## ✔️ Dot Product (Scalar Result)

$$\vec{a}\cdot \vec{b} = |a||b|\cos\theta$$

If $\mathbf{a}=(a_1,a_2,a_3), \mathbf{b}=(b_1,b_2,b_3)$:
$$\vec{a}\cdot\vec{b}=a_1b_1+a_2b_2+a_3b_3$$

### Used in:
* **Angle** between vectors
* **Projection**
* **Perpendicularity test** ($\vec{a}\cdot \vec{b}=0$)

---

## ✔️ Cross Product (Vector Result)

$$\vec{a}\times \vec{b} =
\begin{vmatrix}
\hat{i} & \hat{j} & \hat{k}\\
a_1 & a_2 & a_3\\
b_1 & b_2 & b_3
\end{vmatrix}$$

### Gives:
* A **perpendicular vector** to both $\vec{a}$ and $\vec{b}$
* **Area of Parallelogram:** $\text{Area} = |\vec{a}\times \vec{b}|$ 

[Image of Parallelogram area defined by two vectors]

* **Area of Triangle:** $\text{Area} = \frac{1}{2} |\vec{a}\times \vec{b}|$

---

# ⭐ PART B — SCALAR TRIPLE PRODUCT (STP) (MOST IMPORTANT)

$$[a,b,c] = \mathbf{a} \cdot (\mathbf{b} \times \mathbf{c})$$

**Geometric meaning:**

$$\text{Volume of Parallelepiped} = |[\mathbf{a},\mathbf{b},\mathbf{c}]|$$
$$\text{Volume of Tetrahedron} = \frac{|[\mathbf{a},\mathbf{b},\mathbf{c}]|}{6}$$

---

## ✔️ Example (past paper style)

Find volume of tetrahedron with edges:
$$\mathbf{a}=(1,2,3),\quad \mathbf{b}=(2,1,1),\quad \mathbf{c}=(3,-1,1)$$

Compute **Box Product** $|[\mathbf{a},\mathbf{b},\mathbf{c}]|$:
$$[\mathbf{a},\mathbf{b},\mathbf{c}] =
\begin{vmatrix}
1 & 2 & 3 \\
2 & 1 & 1 \\
3 & -1 & 1
\end{vmatrix}
= 1(1+1) - 2(2-3) + 3(-2-3)$$
$$= 2 + 2 + (-15) = -11$$

Volume:
$$V = \frac{|[\mathbf{a},\mathbf{b},\mathbf{c}]|}{6} = \frac{|-11|}{6} = \frac{11}{6} \text{ cubic units}$$

---

# ⭐ PART C — COLLINEARITY & COPLANARITY

## ✔️ Collinear Vectors (Parallel)

Vectors $\mathbf{a}$ and $\mathbf{b}$ are **collinear** $\iff \mathbf{a} = k \mathbf{b}$ for some scalar $k$.

**Check:** The ratios of the corresponding components must be equal:
$$\frac{a_1}{b_1} = \frac{a_2}{b_2} = \frac{a_3}{b_3}$$

## ✔️ Coplanar Vectors (3 vectors)

Three vectors $\mathbf{a}, \mathbf{b}, \mathbf{c}$ are **coplanar** $\iff$ their **Scalar Triple Product is zero:**
$$[\mathbf{a},\mathbf{b},\mathbf{c}] = 0$$

---

# ⭐ PART D — VECTOR EQUATIONS

## ✔️ Line passing through $\mathbf{a}$ parallel to $\mathbf{b}$
$$\mathbf{r} = \mathbf{a} + \lambda \mathbf{b}$$

## ✔️ Plane passing through point $\mathbf{a}$ with normal vector $\mathbf{n}$
$$\mathbf{r} \cdot \mathbf{n} = \mathbf{a} \cdot \mathbf{n} = d$$

---

# ⭐ PART E — Angle between vectors

$$\cos\theta = \frac{\mathbf{a} \cdot \mathbf{b}}{|\mathbf{a}||\mathbf{b}|}$$

---

# 🔥 VECTOR QUICK BOX

* **Volume of Tetrahedron** $\to$ **$|[a,b,c]|/6$**
* **Area of Triangle** $\to$ **$|a\times b|/2$**
* **Collinear** $\to$ check ratios of components (or $\mathbf{a} \times \mathbf{b} = 0$)
* **Coplanar** $\to$ **STP = 0**
* **Angle** $\to$ Dot product formula

---

# 🎯 If you want, I can now generate:

### ✅ **A PDF with all these notes (properly formatted like OS one)**

### or

### ✅ **A 10-page Rapid Revision Maths PDF**

### or

### ✅ **Last 2-hour cram sheet specifically for tomorrow's exam**

Just tell me:

**“Make the Maths PDF”** or
**“Make the 2-hour cram sheet”**
