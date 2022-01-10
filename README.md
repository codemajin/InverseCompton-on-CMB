# InverseCompton-on-CMB

Spectral calculation of relativistic electron and CMB inverse Compton radiation

<div align="center">
  <img src="https://photojournal.jpl.nasa.gov/jpegMod/PIA03606_modest.jpg">
    <p>NASA/ESA/JPL/Arizona State University</p>
</div>


## Inverse Compton Model

### The ICS onto a monochromatic and isotropic photon spectrum

####  Jones Aproxomation

Assuming that the energy of the photon before scattering is $\alpha$, the energy after scattering is $\alpha_1$, and the Lorentz factor of the electron is $\gamma$、 the spectrum is as follows. The energy of photons is normalized by the rest mass energy of electrons.

- Case where photon energy decreases after scattering : $\displaystyle {\alpha \over 4\gamma^2} \leq \alpha_1 \leq \alpha$

$$
{dN_1 \over dt_1 d\alpha_1} = {\pi r_0^2 c \over 2\gamma^4 \alpha}
 \biggl( {4\gamma^2 \alpha_1 \over \alpha}-1\biggr)
$$

- Case where photon energy rises after scattering : $\displaystyle \alpha \leq \alpha_1 \leq {4\alpha \gamma^2 \over (1+4\alpha \gamma)}$

$$
{dN_1 \over dt_1 d\alpha_1} = {2\pi r_0^2 c\over \alpha \gamma^2}
 \biggl[ 2q\ln q +(1+2q)(1-q)+{1\over 2}{(4\alpha \gamma q)^2 \over
 (1+4\alpha \gamma q)}(1-q)\biggr] \\
q = {\alpha_1 \over 4\alpha \gamma^2 (1- \alpha_1 / \gamma )},
 \hspace{7mm} {1\over 4\gamma^2} < q \leq 1 \hspace{20mm} \nonumber
$$

#### Thomson Approxomation

Assuming that the energy of the photon before scattering is $\varepsilon$, the energy after scattering is $\varepsilon_1$, and the Lorentz factor of the electron is $\gamma$、 the spectrum is as follows. The energy of photons is normalized by the rest mass energy of electrons.

- Case where photon energy decreases after scattering :  $\displaystyle {(1-\beta)\hat{\varepsilon} \over 1+\beta }\leq \varepsilon_1 \leq\hat{\varepsilon}$

$$
{dN_{1isoL} \over dt_1 d\varepsilon_1} &=& {\pi nr_0^2 c\over 4\beta^6
 \gamma^2 \hat{\varepsilon}} \biggl( {\varepsilon_1 \over
 \hat{\varepsilon}} (1+\beta )[\beta (\beta^2 +3)+{1\over \gamma^2
 }(9-4\beta^2 )] \nonumber \\
&\ & +(1-\beta )[\beta (\beta^2 +3)-{1\over \gamma^2
 }(9-4\beta^2 )] -{2\over \gamma^2 } \nonumber \\
&\ & \cdot (3 -\beta^2 )(1+{\varepsilon_1 \over
 \hat{\varepsilon}}) \ln \bigl[{\varepsilon_1 (1+\beta )\over
 \hat{\varepsilon} (1-\beta)} \bigr] -{\hat{\varepsilon} \over \gamma^4
 \varepsilon_1} +{\varepsilon_1^2 \over \gamma^4 \hat{\varepsilon}^2} \biggr)
$$

- Case where photon energy rises after scattering :  $\displaystyle \hat{\varepsilon} \leq \varepsilon_1 \leq {(1+\beta)\hat{\varepsilon}\over 1-\beta}$

$$
{dN_{1isoR} \over dt_1 d\varepsilon_1} &=& {\pi nr_0^2 c\over 4\beta^6
 \gamma^2 \hat{\varepsilon}} \biggl( (1+\beta )[\beta (\beta^2
 +3)+{1\over \gamma^2 }(9-4\beta^2 )] \nonumber \\
&\ & +{\varepsilon_1 \over
 \hat{\varepsilon}}(1-\beta )[\beta (\beta^2 +3)-{1\over \gamma^2
 }(9-4\beta^2 )] -{2\over \gamma^2 } \nonumber \\
&\ & \cdot (3 -\beta^2 )(1+{\varepsilon_1 \over
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