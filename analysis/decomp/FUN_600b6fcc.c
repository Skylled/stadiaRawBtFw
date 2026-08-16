// 600b6fcc  FUN_600b6fcc  size=172 bytes
// --- callers ---
//   600b5e00 FUN_600b5e00
// --- callees ---
//   600f99ee FUN_600f99ee
//   6006ddd8 FUN_6006ddd8
//   600bc00c FUN_600bc00c


void FUN_600b6fcc(undefined2 *param_1,undefined2 param_2,undefined4 param_3)

{
  undefined2 uVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(*(int *)(param_1 + 0xaa) + 0x20);
  uVar1 = *param_1;
  switch(param_2) {
  case 3:
  case 0x20:
    FUN_600bc00c(param_1);
    if (pcVar2 != (code *)0x0) {
      (*pcVar2)(uVar1,0xeeee);
    }
    break;
  case 0x11:
    FUN_600f99ee(*(undefined4 *)(param_1 + 0x96),*(undefined1 *)(param_1 + 4),*param_1,param_1[1]);
    FUN_600bc00c(param_1);
    if (pcVar2 != (code *)0x0) {
      (*pcVar2)(uVar1,0);
    }
    break;
  case 0x12:
    FUN_600bc00c(param_1);
    if (pcVar2 != (code *)0x0) {
      (*pcVar2)(uVar1,0);
    }
    break;
  case 0x14:
  case 0x1e:
    FUN_6006ddd8(param_3,DAT_600b70f0,0x489);
  }
  return;
}


