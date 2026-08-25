// 600f9462  FUN_600f9462  size=1188 bytes
// --- callers ---
//   600b6900 FUN_600b6900
//   600b6d30 FUN_600b6d30
// --- callees ---
//   600b9408 FUN_600b9408
//   600bb7e4 FUN_600bb7e4


void FUN_600f9462(int param_1,undefined2 *param_2)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *local_10;
  short local_a;
  
  local_a = 0;
  if (*(char *)(param_2 + 1) != '\0') {
    local_a = 4;
  }
  if (*(char *)(param_2 + 0x10) != '\0') {
    local_a = local_a + 4;
  }
  if (*(char *)(param_2 + 3) != '\0') {
    local_a = local_a + 0x18;
  }
  if (*(char *)(param_2 + 0x12) != '\0') {
    local_a = local_a + 0xb;
  }
  if (*(char *)(param_2 + 0x19) != '\0') {
    local_a = local_a + 0x12;
  }
  iVar1 = FUN_600bb7e4(*(undefined4 *)(param_1 + 300),local_a + 6,5,*(undefined1 *)(param_1 + 8));
  if (iVar1 != 0) {
    *(char *)(iVar1 + 0x14) = (char)*(undefined2 *)(param_1 + 2);
    *(char *)(iVar1 + 0x15) = (char)((ushort)*(undefined2 *)(param_1 + 2) >> 8);
    *(char *)(iVar1 + 0x16) = (char)param_2[0x22];
    *(char *)(iVar1 + 0x17) = (char)((ushort)param_2[0x22] >> 8);
    *(char *)(iVar1 + 0x18) = (char)*param_2;
    local_10 = (undefined1 *)(iVar1 + 0x1a);
    *(char *)(iVar1 + 0x19) = (char)((ushort)*param_2 >> 8);
    if (*(char *)(param_2 + 1) != '\0') {
      *local_10 = 1;
      *(undefined1 *)(iVar1 + 0x1b) = 2;
      *(char *)(iVar1 + 0x1c) = (char)param_2[2];
      local_10 = (undefined1 *)(iVar1 + 0x1e);
      *(char *)(iVar1 + 0x1d) = (char)((ushort)param_2[2] >> 8);
    }
    if (*(char *)(param_2 + 0x10) != '\0') {
      *local_10 = 2;
      local_10[1] = 2;
      puVar2 = local_10 + 3;
      local_10[2] = (char)param_2[0x11];
      local_10 = local_10 + 4;
      *puVar2 = (char)((ushort)param_2[0x11] >> 8);
    }
    if (*(char *)(param_2 + 3) != '\0') {
      *local_10 = 3;
      local_10[1] = 0x16;
      local_10[2] = *(undefined1 *)(param_2 + 4);
      local_10[3] = *(undefined1 *)((int)param_2 + 9);
      local_10[4] = (char)*(undefined4 *)(param_2 + 6);
      local_10[5] = (char)((uint)*(undefined4 *)(param_2 + 6) >> 8);
      local_10[6] = (char)((uint)*(undefined4 *)(param_2 + 6) >> 0x10);
      local_10[7] = (char)((uint)*(undefined4 *)(param_2 + 6) >> 0x18);
      local_10[8] = (char)*(undefined4 *)(param_2 + 8);
      local_10[9] = (char)((uint)*(undefined4 *)(param_2 + 8) >> 8);
      local_10[10] = (char)((uint)*(undefined4 *)(param_2 + 8) >> 0x10);
      local_10[0xb] = (char)((uint)*(undefined4 *)(param_2 + 8) >> 0x18);
      local_10[0xc] = (char)*(undefined4 *)(param_2 + 10);
      local_10[0xd] = (char)((uint)*(undefined4 *)(param_2 + 10) >> 8);
      local_10[0xe] = (char)((uint)*(undefined4 *)(param_2 + 10) >> 0x10);
      local_10[0xf] = (char)((uint)*(undefined4 *)(param_2 + 10) >> 0x18);
      local_10[0x10] = (char)*(undefined4 *)(param_2 + 0xc);
      local_10[0x11] = (char)((uint)*(undefined4 *)(param_2 + 0xc) >> 8);
      local_10[0x12] = (char)((uint)*(undefined4 *)(param_2 + 0xc) >> 0x10);
      local_10[0x13] = (char)((uint)*(undefined4 *)(param_2 + 0xc) >> 0x18);
      local_10[0x14] = (char)*(undefined4 *)(param_2 + 0xe);
      local_10[0x15] = (char)((uint)*(undefined4 *)(param_2 + 0xe) >> 8);
      puVar2 = local_10 + 0x17;
      local_10[0x16] = (char)((uint)*(undefined4 *)(param_2 + 0xe) >> 0x10);
      local_10 = local_10 + 0x18;
      *puVar2 = (char)((uint)*(undefined4 *)(param_2 + 0xe) >> 0x18);
    }
    if (*(char *)(param_2 + 0x12) != '\0') {
      *local_10 = 4;
      local_10[1] = 9;
      local_10[2] = *(undefined1 *)(param_2 + 0x13);
      local_10[3] = *(undefined1 *)((int)param_2 + 0x27);
      local_10[4] = *(undefined1 *)(param_2 + 0x14);
      local_10[5] = (char)*(undefined2 *)(param_1 + 0x36);
      local_10[6] = (char)((ushort)*(undefined2 *)(param_1 + 0x36) >> 8);
      local_10[7] = (char)*(undefined2 *)(param_1 + 0x38);
      local_10[8] = (char)((ushort)*(undefined2 *)(param_1 + 0x38) >> 8);
      puVar2 = local_10 + 10;
      local_10[9] = (char)param_2[0x17];
      local_10 = local_10 + 0xb;
      *puVar2 = (char)((ushort)param_2[0x17] >> 8);
    }
    if (*(char *)(param_2 + 0x19) != '\0') {
      *local_10 = 6;
      local_10[1] = 0x10;
      local_10[2] = *(undefined1 *)(param_2 + 0x1a);
      local_10[3] = *(undefined1 *)((int)param_2 + 0x35);
      local_10[4] = (char)param_2[0x1b];
      local_10[5] = (char)((ushort)param_2[0x1b] >> 8);
      local_10[6] = (char)*(undefined4 *)(param_2 + 0x1c);
      local_10[7] = (char)((uint)*(undefined4 *)(param_2 + 0x1c) >> 8);
      local_10[8] = (char)((uint)*(undefined4 *)(param_2 + 0x1c) >> 0x10);
      local_10[9] = (char)((uint)*(undefined4 *)(param_2 + 0x1c) >> 0x18);
      local_10[10] = (char)*(undefined4 *)(param_2 + 0x1e);
      local_10[0xb] = (char)((uint)*(undefined4 *)(param_2 + 0x1e) >> 8);
      local_10[0xc] = (char)((uint)*(undefined4 *)(param_2 + 0x1e) >> 0x10);
      local_10[0xd] = (char)((uint)*(undefined4 *)(param_2 + 0x1e) >> 0x18);
      local_10[0xe] = (char)*(undefined4 *)(param_2 + 0x20);
      local_10[0xf] = (char)((uint)*(undefined4 *)(param_2 + 0x20) >> 8);
      local_10[0x10] = (char)((uint)*(undefined4 *)(param_2 + 0x20) >> 0x10);
      local_10[0x11] = (char)((uint)*(undefined4 *)(param_2 + 0x20) >> 0x18);
    }
    FUN_600b9408(*(undefined4 *)(param_1 + 300),0,iVar1);
  }
  return;
}


