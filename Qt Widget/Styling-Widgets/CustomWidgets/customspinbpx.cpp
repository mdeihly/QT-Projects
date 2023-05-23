#include "customspinbpx.h"

CustomSpinBpx::CustomSpinBpx(QWidget *parent)
    : QSpinBox{parent}
{
    setMinimum(0);
    setMaximum(80);
    setValue(5);
}
