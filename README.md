# InverseCompton-on-CMB

Spectral calculation of relativistic electron and CMB inverse Compton radiation

<img src="https://scx2.b-cdn.net/gfx/news/hires/2014/1-crabnebula.jpg" alt="50" style="zoom:100%;" />

*The Crab Nebula. Credit: NASA*

## Inverse Compton Model

### The ICS onto a monochromatic and isotropic photon spectrum

####  Jones Approximation

Assuming that the energy of the photon before scattering is $\alpha$, the energy after scattering is $\alpha_1$, and the Lorentz factor of the electron is $\gamma$、 the spectrum is as follows. The energy of photons is normalized by the rest mass energy of electrons.

- Case where photon energy decreases after scattering : $\displaystyle {\alpha \over 4\gamma^2} \leq \alpha_1 \leq \alpha$

$$
{dN_1 \over dt_1 d\alpha_1} = {\pi r_0^2 c \over 2\gamma^4 \alpha} \biggl( {4\gamma^2 \alpha_1 \over \alpha}-1\biggr)
$$

- Case where photon energy rises after scattering : $\displaystyle \alpha \leq \alpha_1 \leq {4\alpha \gamma^2 \over (1+4\alpha \gamma)}$

$$
\begin{eqnarray}
{dN_1 \over dt_1 d\alpha_1} = {2\pi r_0^2 c\over \alpha \gamma^2} \biggl[ 2q\ln q +(1+2q)(1-q)+{1\over 2}{(4\alpha \gamma q)^2 \over (1+4\alpha \gamma q)}(1-q)\biggr] \\
q = {\alpha_1 \over 4\alpha \gamma^2 (1- \alpha_1 / \gamma )}, \hspace{7mm} {1\over 4\gamma^2} < q \leq 1 \hspace{20mm} \nonumber
\end{eqnarray}
$$

#### Thomson Approximation

Assuming that the energy of the photon before scattering is $\varepsilon$, the energy after scattering is $\varepsilon_1$, and the Lorentz factor of the electron is $\gamma$、 the spectrum is as follows. The energy of photons is normalized by the rest mass energy of electrons.

- Case where photon energy decreases after scattering :  $\displaystyle {(1-\beta)\hat{\varepsilon} \over 1+\beta }\leq \varepsilon_1 \leq\hat{\varepsilon}$

$$
{dN_{1isoL} \over dt_1 d\varepsilon_1} = {\pi nr_0^2 c\over 4\beta^6
 \gamma^2 \hat{\varepsilon}} \biggl( {\varepsilon_1 \over
 \hat{\varepsilon}} (1+\beta )[\beta (\beta^2 +3)+{1\over \gamma^2
 }(9-4\beta^2 )]
 +(1-\beta )[\beta (\beta^2 +3)-{1\over \gamma^2
 }(9-4\beta^2 )] -{2\over \gamma^2 } 
 \cdot (3 -\beta^2 )(1+{\varepsilon_1 \over
 \hat{\varepsilon}}) \ln \bigl[{\varepsilon_1 (1+\beta )\over
 \hat{\varepsilon} (1-\beta)} \bigr] -{\hat{\varepsilon} \over \gamma^4
 \varepsilon_1} +{\varepsilon_1^2 \over \gamma^4 \hat{\varepsilon}^2} \biggr)
$$

- Case where photon energy rises after scattering :  $\displaystyle \hat{\varepsilon} \leq \varepsilon_1 \leq {(1+\beta)\hat{\varepsilon}\over 1-\beta}$

$$
{dN_{1isoR} \over dt_1 d\varepsilon_1} = {\pi nr_0^2 c\over 4\beta^6
 \gamma^2 \hat{\varepsilon}} \biggl( (1+\beta )[\beta (\beta^2
 +3)+{1\over \gamma^2 }(9-4\beta^2 )] 
 +{\varepsilon_1 \over
 \hat{\varepsilon}}(1-\beta )[\beta (\beta^2 +3)-{1\over \gamma^2
 }(9-4\beta^2 )] -{2\over \gamma^2 }
 \cdot (3 -\beta^2 )(1+{\varepsilon_1 \over
 \hat{\varepsilon}}) \ln \bigl[{\hat{\varepsilon} (1+\beta )\over
 \varepsilon_1 (1-\beta)} \bigr] +{\hat{\varepsilon} \over \gamma^4
 \varepsilon_1} -{\varepsilon_1^2 \over \gamma^4 \hat{\varepsilon}^2} \biggr)
$$

### ICS energy flux when the target photon is CMB

The energy flux of CMB is as follows :

$$
n(\hat{\varepsilon}) = {1 \over \pi^2 \hbar^3 c^3}{\hat{\varepsilon}^2 \over
 \exp (\hat{\varepsilon} /k_B T)-1}
$$

Also, the energy flux of electrons is as follows :

$$
\phi_e (\gamma) = N_0 \gamma^{-p} \exp \biggl( -{\gamma \over
 \gamma_{max} }\biggr)
$$

From the above, the flux emitted from the astrophysical object at the distance $D$ is observed as the following quantity on the earth.

$$
F_{\varepsilon_1} = {1\over 4\pi D^2}
 \int_{\gamma}\int_{\hat{\varepsilon}}d\gamma
 d\hat{\varepsilon}\phi_e(\gamma) n(\hat{\varepsilon}){1\over
 4\pi}\int_{\Omega}{dN_1 \over dt_1 d{\varepsilon_1}}d\Omega
$$

## Jones approximation vs. Thomson approximation

By comparing the Jones approximation and the Thomson approximation, the following can be clearly seen:

1. The radiation efficiency of inverse Compton scattering decreases with increasing energy due to the decrease in scattering cross section indicated by the Klein-Nishina formula.
2. The energy of the emitted photon shows a loose dependence on the square to the first power of the Lorentz factor of the electron.

| Maximum Lorentz Factor of electron  | Multi-energy range                                                                                                                 | Gamma-ray focus |
| ----------------------- | ---------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------- |
| `1.0E+6`                  | ![multi-wave-length-1 0E+6](https://user-images.githubusercontent.com/20922926/149614483-01263282-9410-4bab-b384-46ebfb4155db.png) | ![gamma-ray-1 0E 6](https://user-images.githubusercontent.com/20922926/149614477-bf4596d3-1022-44c7-9d3c-7cd2c96b544f.png) |
| `1.0E+7`                  | ![multi-wave-kength-1 0E+7](https://user-images.githubusercontent.com/20922926/149614482-c7e99876-fc4e-475d-859f-2127585a404a.png) | ![gamma-ray-1 0E+7](https://user-images.githubusercontent.com/20922926/149614479-56589f51-1d0c-4507-b362-e7a1e83d4d7f.png) |
| `1.0E+8`                  | ![multi-wave-length-1 0E+8](https://user-images.githubusercontent.com/20922926/149614484-c298179d-dd55-4407-96f5-47a9e1ce5983.png) | ![gamma-ray-1 0E+8](https://user-images.githubusercontent.com/20922926/149614480-245de1ee-40c9-44d4-a112-a5ba596777a8.png) |

## Application to the Crab Nebula

![graph](https://user-images.githubusercontent.com/20922926/148781142-546f2860-45cf-4898-9d59-f8540f411f75.png)

## References

1. [D.Fargion et al., 1996, arXiv:astro-ph/9606126v1](https://arxiv.org/abs/astro-ph/9606126)
2. [F.C Jones, 1968, Phys.Rev., 167, 1159](https://journals.aps.org/pr/abstract/10.1103/PhysRev.167.1159)
3. [G.R.Blumenthal, R.J.Gould, Rev.Mod.Phys. 42 (1970) 237.](https://journals.aps.org/rmp/abstract/10.1103/RevModPhys.42.237)
