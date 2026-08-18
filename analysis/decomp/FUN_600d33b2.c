// 600d33b2  FUN_600d33b2  size=126 bytes
// --- callers ---
//   600d28b8 FUN_600d28b8
//   60056fa4 FUN_60056fa4
//   60064dac usb_host_hid__60064dac
//   600563b8 FUN_600563b8
//   600d201e FUN_600d201e
//   600d2dba FUN_600d2dba
//   600626e4 usb_host__600626e4
//   60056b48 FUN_60056b48
//   600d190a FUN_600d190a
//   60055fbc FUN_60055fbc
//   60056610 FUN_60056610
//   600d1ea2 FUN_600d1ea2
//   60057c78 FUN_60057c78
//   600637cc FUN_600637cc
//   600d27b4 FUN_600d27b4
//   600d2bb0 FUN_600d2bb0
//   600565c4 FUN_600565c4
//   60056c38 FUN_60056c38
//   60056578 FUN_60056578
// --- callees ---
//   60056610 FUN_60056610


undefined4 FUN_600d33b2(int param_1,undefined4 param_2,uint *param_3)

{
  uint uVar1;
  
  if ((param_1 != 0) && (param_3 != (uint *)0x0)) {
    switch(param_2) {
    case 1:
      uVar1 = (uint)*(byte *)(param_1 + 0x43d);
      break;
    case 2:
      uVar1 = (uint)*(byte *)(param_1 + 0x43f);
      break;
    case 3:
      uVar1 = (uint)*(byte *)(param_1 + 0x440);
      break;
    case 4:
      uVar1 = (uint)*(byte *)(param_1 + 0x43b);
      break;
    case 5:
      uVar1 = (uint)*(byte *)(param_1 + 0x441);
      break;
    case 6:
      uVar1 = (uint)*(byte *)(param_1 + 0x442);
      break;
    case 7:
      uVar1 = (uint)*(byte *)(param_1 + 0x443);
      break;
    case 8:
      uVar1 = *(uint *)(param_1 + 4);
      break;
    case 9:
      uVar1 = *(uint *)(param_1 + 0x418);
      break;
    case 10:
      uVar1 = (uint)*(ushort *)(*(int *)(param_1 + 0x414) + 10);
      break;
    case 0xb:
      uVar1 = (uint)*(ushort *)(*(int *)(param_1 + 0x414) + 8);
      break;
    case 0xc:
      uVar1 = FUN_60056610(*(undefined4 *)(param_1 + 4),*(undefined1 *)(param_1 + 0x43f));
      *param_3 = uVar1;
      return 0;
    case 0xd:
      uVar1 = *(ushort *)(param_1 + 0x422) - 1;
      break;
    case 0xe:
      uVar1 = *(uint *)(param_1 + 0x41c);
      break;
    case 0xf:
      uVar1 = (uint)*(ushort *)(param_1 + 0x420);
      break;
    default:
      return 1;
    }
    *param_3 = uVar1;
    return 0;
  }
  return 4;
}


