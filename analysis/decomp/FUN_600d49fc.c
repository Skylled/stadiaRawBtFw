// 600d49fc  FUN_600d49fc  size=130 bytes
// --- callers ---
//   600cbdc8 xbara__600cbdc8
// --- callees ---
//   60060170 xbara__60060170


void FUN_600d49fc(undefined1 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 4);
  switch(*param_1) {
  case 0:
    xbara__60060170(uVar1,0x101,0x123);
    uVar1 = 0x124;
    break;
  case 1:
    xbara__60060170(uVar1,0x101,0x131);
    uVar1 = 0x132;
    break;
  case 2:
    xbara__60060170(uVar1,0x101,0x138);
    uVar1 = 0x139;
    break;
  case 3:
    xbara__60060170(uVar1,0x101,0x13f);
    uVar1 = 0x140;
    break;
  default:
    goto switchD_600d4a08_default;
  }
  xbara__60060170(*(undefined4 *)(param_1 + 4),0x101,uVar1);
switchD_600d4a08_default:
  xbara__60060170(*(undefined4 *)(param_1 + 4),0x101,0x125);
  xbara__60060170(*(undefined4 *)(param_1 + 4),0x101,0x126);
  return;
}


