import os
import sys
import subprocess
from os import environ, path
from subprocess import call
from setuptools import setup
from setuptools.command.install import install

application_name='simpleconvert'
datadir = path.join(sys.prefix, 'share')

trandir = path.join(datadir, 'locale')
local_podir = 'po'

class InstallGtk(install):

    def run(self):
        """Run custom commands needed for GTK

        Create required folders, run the default setup,
        update icon cache and desktop files database
        """
        if not os.path.exists(path.join(datadir, application_name)):
            os.makedirs(path.join(datadir, application_name))

        print('Installing translations...')

        for file in os.listdir(local_podir):
            filename = os.fsdecode(file)
            lang_code = filename[:-3]

            if filename.endswith('.po'):
                call(['msgfmt', path.join(local_podir, filename), '-o', path.join(trandir, lang_code, 'LC_MESSAGES', application_name + '.mo')])

        install.run(self)

        print('Updating icon cache...')
        call(['gtk-update-icon-cache', '-qtf', path.join(datadir, 'icons', 'hicolor')])

        print('Updating desktop database...')
        call(['update-desktop-database', '-q', path.join(datadir, 'applications')])


setup(
    name='Simple Convert',
    version='1.0',
    author='Bart Kessels',
    author_email='bartkessels@bk-mail.com',
    description='Application to convert multiple files to another filetype',

    license='GPLv3+',
    url='https://github.com/bartkessels/simpleconvert',

    entry_points={
        'gui_scripts': [
            'simpleconvert = simpleconvert.main:main'
        ],
    },

    packages=[
        'simpleconvert',
    ],

    install_requires=[
        'pygobject>=3.24',
        'ffmpeg-python>=0.1.9',
        'python-gettext'
    ],

    package_data={
        'simpleconvert':['ui/mainwindow.glade']
    },
    include_package_data=True,

    data_files=[
        ('share/applications', ['data/net.bartkessels.simpleconvert.desktop']),
        ('share/appdata', ['data/net.bartkessels.simpleconvert.appdata.xml'])
    ],

    cmdclass={
        'install':InstallGtk,
    },
)

