# Information about AeroThemePlasma
If you're using [AeroThemePlasma](https://gitgud.io/wackyideas/aerothemeplasma) as your KDE Plasma theme, here's how you can allow my Qt recreation apps to use it:
The following instructions will be mainly for Arch Linux and other pacman based distros, but apt-based ones can work too.

### 1. Install Packages
• Arch Linux / Pacman-based:
```bash
sudo pacman -S qt5ct kvantum-qt5
```
• Kubuntu / Debian-based:
```bash
sudo apt install qt5ct qt5-style-kvantum
```

### 2. Set Up Configuration
• Launch qt5ct:
```bash
qt5ct
```
• Select `kvantum` in the "Style:" box.
• Go to the 'Icon Theme' tab
• Select 'Windows 7 Aero'
• Press OK

### 3. Make Qt use qt5ct
• If you want to temporarily set the environment variable:
```bash
export QT_QPA_PLATFORMTHEME=qt5ct
```
• Otherwise, if you want it to apply system-wide, edit the `/etc/environment` file using your preferred text editor:
```bash
sudo nano /etc/environment
```
• then add the following to the end:
```bash
export QT_QPA_PLATFORMTHEME=qt5ct
```
• And finally, log out and in again (or simply reboot)

The Qt applications will now use AeroThemePlasma as the theme! Not everything will look 100% correct but it's close enough methinks. These are all open source anyways ofc so if you want to edit in your own theme then by all means, go ahead!