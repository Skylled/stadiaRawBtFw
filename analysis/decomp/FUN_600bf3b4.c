// 600bf3b4  FUN_600bf3b4  size=430 bytes
// --- callers ---
//   600bfeec FUN_600bfeec
//   600be558 FUN_600be558
//   600beb20 FUN_600beb20
// --- callees ---


undefined1 * FUN_600bf3b4(undefined1 *param_1,uint *param_2)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  undefined1 *local_c;
  
  *param_1 = 9;
  param_1[1] = (char)((ushort)(short)param_2[2] >> 8);
  pbVar1 = param_1 + 3;
  param_1[2] = (char)(short)param_2[2];
  uVar2 = (uint)*(byte *)((int)param_2 + 10);
  if ((uVar2 == 4) || ((3 < uVar2 && (uVar2 - 6 < 3)))) {
    if (*param_2 < 0x100) {
      *pbVar1 = *(char *)((int)param_2 + 10) << 3 | 5;
      local_c = param_1 + 5;
      param_1[4] = (char)*param_2;
    }
    else {
      *pbVar1 = *(char *)((int)param_2 + 10) << 3 | 6;
      param_1[4] = (char)(*param_2 >> 8);
      local_c = param_1 + 6;
      param_1[5] = (char)*param_2;
    }
    for (iVar3 = 0; iVar3 < (int)*param_2; iVar3 = iVar3 + 1) {
      *local_c = *(undefined1 *)(iVar3 + param_2[1]);
      local_c = local_c + 1;
    }
  }
  else {
    switch(*param_2) {
    case 1:
      local_c = param_1 + 4;
      *pbVar1 = *(char *)((int)param_2 + 10) << 3;
      break;
    case 2:
      local_c = param_1 + 4;
      *pbVar1 = *(char *)((int)param_2 + 10) << 3 | 1;
      break;
    default:
      *pbVar1 = *(char *)((int)param_2 + 10) << 3 | 5;
      local_c = param_1 + 5;
      param_1[4] = (char)*param_2;
      break;
    case 4:
      local_c = param_1 + 4;
      *pbVar1 = *(char *)((int)param_2 + 10) << 3 | 2;
      break;
    case 8:
      local_c = param_1 + 4;
      *pbVar1 = *(char *)((int)param_2 + 10) << 3 | 3;
      break;
    case 0x10:
      local_c = param_1 + 4;
      *pbVar1 = *(char *)((int)param_2 + 10) << 3 | 4;
    }
    for (iVar3 = 0; iVar3 < (int)*param_2; iVar3 = iVar3 + 1) {
      *local_c = *(undefined1 *)(iVar3 + param_2[1]);
      local_c = local_c + 1;
    }
  }
  return local_c;
}


