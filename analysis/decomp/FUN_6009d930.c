// 6009d930  FUN_6009d930  size=142 bytes
// --- callers ---
//   6009dc14 FUN_6009dc14
//   6009daac FUN_6009daac
// --- callees ---


void FUN_6009d930(int param_1,undefined1 param_2,undefined2 *param_3,undefined2 *param_4)

{
  if ((*(short *)(param_1 + 10) == 0) || (*(short *)(param_1 + 0xc) == 0)) {
    switch(param_2) {
    case 0:
    case 4:
      *param_4 = 0x30;
      *param_3 = *param_4;
      break;
    case 1:
      *param_3 = 400;
      *param_4 = 800;
      break;
    case 2:
    case 3:
      *param_4 = 0xa0;
      *param_3 = *param_4;
      break;
    default:
      *param_4 = 0x800;
      *param_3 = *param_4;
    }
  }
  else {
    *param_3 = *(undefined2 *)(param_1 + 10);
    *param_4 = *(undefined2 *)(param_1 + 0xc);
  }
  return;
}


