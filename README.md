# A ~Colemak~ QWERTY keymap for the Redox keyboard 
## My interpretation of Jeherve work on Colmak Redox layout

----
![edjubert Redox Layout](https://raw.githubusercontent.com/edjubert/redox-layout/master/redox---qwerty.png)

----

This keymap is **a work in progress**, and is meant to be used on macOS.
I use this keymap with a Colemak input layout of MacOS.
There is also a Colemak version available on the `colemak` branch, a Dvorak version on the `dvorak` branch and a Programmer Mod on `programmer_qwerty`,`programmer_colemak` and `programmer_dvorak` branches

[View on KLE](http://www.keyboard-layout-editor.com/#/gists/a320cd783e183d8b9637d3862794c433)

## Installation

Clone this repo under
```bash
qmk_firmware_folder/keyboards/redox/keymaps
```

Build it with
```bash
make redox:edjubert
```

## Layers

My layout uses 5 layers:

1. The default base layer, using [QWERTY].
2. A Symbol layer, so dev specific symbols are accessible from the home row.
3. A Navigation / Media layer, with both sound control, mouse and arrows on the home row. (bottom right legends)
4. An international layer (_inter), empty for the moment.
5. A keyboard control layer, not pictured here, allowing me to control the LED lighting as well as the keyboard debug functions.

This is a customization of Jeherve available [here](https://github.com/jeherve/redox-layout).

## Programmer mod
This mod is inspired by programmer [programmer dvorak layout](https://www.slant.co/options/18047/~programmer-dvorak-review)
But I didn't swap numbers and special chars, maybe due to AZERTY like allergy.
This mod is more to test if it is more natural to write numbers this way as I still cannot get use of the 1234567890 layout.

## Credits

- Redox keyboard design by [Mattia Dal Ben](https://github.com/mattdibi/redox-keyboard).
- This keymap is based off the default keymap for the Redox keyboard, available [here](https://github.com/qmk/qmk_firmware/tree/master/keyboards/redox) and also build by Mattia Dal Ben (thank you!).
- This layout uses [QMK keyboard controller firmware](https://github.com/qmk/qmk_firmware/).

- I reuse a change the layout of jeherve for my own needs. Take a look at jeherve work [here](https://github.com/jeherve/redox-layout)
- Also an adaptation of Programmer Dvorak. [See the review here](https://www.slant.co/options/18047/~programmer-dvorak-review)
