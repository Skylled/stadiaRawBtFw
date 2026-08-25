// 600f8f7a  FUN_600f8f7a  size=1256 bytes
// --- callers ---
//   600b6900 FUN_600b6900
//   600b6d30 FUN_600b6d30
//   600f8664 FUN_600f8664
// --- callees ---
//   600f8c34 FUN_600f8c34
//   600b9408 FUN_600b9408
//   600bb7e4 FUN_600bb7e4


void FUN_600f8f7a(int param_1,int param_2)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *local_10;
  short local_a;
  
  local_a = 0;
  *(char *)(*(int *)(param_1 + 300) + 0xb) = *(char *)(*(int *)(param_1 + 300) + 0xb) + '\x01';
  FUN_600f8c34(*(undefined4 *)(param_1 + 300),3);
  *(undefined1 *)(param_1 + 7) = *(undefined1 *)(*(int *)(param_1 + 300) + 0xb);
  if (*(char *)(param_2 + 2) != '\0') {
    local_a = 4;
  }
  if (*(char *)(param_2 + 0x20) != '\0') {
    local_a = local_a + 4;
  }
  if (*(char *)(param_2 + 6) != '\0') {
    local_a = local_a + 0x18;
  }
  if (*(char *)(param_2 + 0x24) != '\0') {
    local_a = local_a + 0xb;
  }
  if (*(char *)(param_2 + 0x30) != '\0') {
    local_a = local_a + 3;
  }
  if (*(char *)(param_2 + 0x32) != '\0') {
    local_a = local_a + 0x12;
  }
  iVar1 = FUN_600bb7e4(*(undefined4 *)(param_1 + 300),local_a + 4,4,*(undefined1 *)(param_1 + 7));
  if (iVar1 != 0) {
    *(char *)(iVar1 + 0x14) = (char)*(undefined2 *)(param_1 + 2);
    *(char *)(iVar1 + 0x15) = (char)((ushort)*(undefined2 *)(param_1 + 2) >> 8);
    *(char *)(iVar1 + 0x16) = (char)*(undefined2 *)(param_2 + 0x44);
    local_10 = (undefined1 *)(iVar1 + 0x18);
    *(char *)(iVar1 + 0x17) = (char)((ushort)*(undefined2 *)(param_2 + 0x44) >> 8);
    if (*(char *)(param_2 + 2) != '\0') {
      *local_10 = 1;
      *(undefined1 *)(iVar1 + 0x19) = 2;
      *(char *)(iVar1 + 0x1a) = (char)*(undefined2 *)(param_2 + 4);
      local_10 = (undefined1 *)(iVar1 + 0x1c);
      *(char *)(iVar1 + 0x1b) = (char)((ushort)*(undefined2 *)(param_2 + 4) >> 8);
    }
    if (*(char *)(param_2 + 0x20) != '\0') {
      *local_10 = 2;
      local_10[1] = 2;
      puVar2 = local_10 + 3;
      local_10[2] = (char)*(undefined2 *)(param_2 + 0x22);
      local_10 = local_10 + 4;
      *puVar2 = (char)((ushort)*(undefined2 *)(param_2 + 0x22) >> 8);
    }
    if (*(char *)(param_2 + 6) != '\0') {
      *local_10 = 3;
      local_10[1] = 0x16;
      local_10[2] = *(undefined1 *)(param_2 + 8);
      local_10[3] = *(undefined1 *)(param_2 + 9);
      local_10[4] = (char)*(undefined4 *)(param_2 + 0xc);
      local_10[5] = (char)((uint)*(undefined4 *)(param_2 + 0xc) >> 8);
      local_10[6] = (char)((uint)*(undefined4 *)(param_2 + 0xc) >> 0x10);
      local_10[7] = (char)((uint)*(undefined4 *)(param_2 + 0xc) >> 0x18);
      local_10[8] = (char)*(undefined4 *)(param_2 + 0x10);
      local_10[9] = (char)((uint)*(undefined4 *)(param_2 + 0x10) >> 8);
      local_10[10] = (char)((uint)*(undefined4 *)(param_2 + 0x10) >> 0x10);
      local_10[0xb] = (char)((uint)*(undefined4 *)(param_2 + 0x10) >> 0x18);
      local_10[0xc] = (char)*(undefined4 *)(param_2 + 0x14);
      local_10[0xd] = (char)((uint)*(undefined4 *)(param_2 + 0x14) >> 8);
      local_10[0xe] = (char)((uint)*(undefined4 *)(param_2 + 0x14) >> 0x10);
      local_10[0xf] = (char)((uint)*(undefined4 *)(param_2 + 0x14) >> 0x18);
      local_10[0x10] = (char)*(undefined4 *)(param_2 + 0x18);
      local_10[0x11] = (char)((uint)*(undefined4 *)(param_2 + 0x18) >> 8);
      local_10[0x12] = (char)((uint)*(undefined4 *)(param_2 + 0x18) >> 0x10);
      local_10[0x13] = (char)((uint)*(undefined4 *)(param_2 + 0x18) >> 0x18);
      local_10[0x14] = (char)*(undefined4 *)(param_2 + 0x1c);
      local_10[0x15] = (char)((uint)*(undefined4 *)(param_2 + 0x1c) >> 8);
      puVar2 = local_10 + 0x17;
      local_10[0x16] = (char)((uint)*(undefined4 *)(param_2 + 0x1c) >> 0x10);
      local_10 = local_10 + 0x18;
      *puVar2 = (char)((uint)*(undefined4 *)(param_2 + 0x1c) >> 0x18);
    }
    if (*(char *)(param_2 + 0x24) != '\0') {
      *local_10 = 4;
      local_10[1] = 9;
      local_10[2] = *(undefined1 *)(param_2 + 0x26);
      local_10[3] = *(undefined1 *)(param_2 + 0x27);
      local_10[4] = *(undefined1 *)(param_2 + 0x28);
      local_10[5] = (char)*(undefined2 *)(param_2 + 0x2a);
      local_10[6] = (char)((ushort)*(undefined2 *)(param_2 + 0x2a) >> 8);
      local_10[7] = (char)*(undefined2 *)(param_2 + 0x2c);
      local_10[8] = (char)((ushort)*(undefined2 *)(param_2 + 0x2c) >> 8);
      puVar2 = local_10 + 10;
      local_10[9] = (char)*(undefined2 *)(param_2 + 0x2e);
      local_10 = local_10 + 0xb;
      *puVar2 = (char)((ushort)*(undefined2 *)(param_2 + 0x2e) >> 8);
    }
    if (*(char *)(param_2 + 0x30) != '\0') {
      *local_10 = 5;
      puVar2 = local_10 + 2;
      local_10[1] = 1;
      local_10 = local_10 + 3;
      *puVar2 = *(undefined1 *)(param_2 + 0x31);
    }
    if (*(char *)(param_2 + 0x32) != '\0') {
      *local_10 = 6;
      local_10[1] = 0x10;
      local_10[2] = *(undefined1 *)(param_2 + 0x34);
      local_10[3] = *(undefined1 *)(param_2 + 0x35);
      local_10[4] = (char)*(undefined2 *)(param_2 + 0x36);
      local_10[5] = (char)((ushort)*(undefined2 *)(param_2 + 0x36) >> 8);
      local_10[6] = (char)*(undefined4 *)(param_2 + 0x38);
      local_10[7] = (char)((uint)*(undefined4 *)(param_2 + 0x38) >> 8);
      local_10[8] = (char)((uint)*(undefined4 *)(param_2 + 0x38) >> 0x10);
      local_10[9] = (char)((uint)*(undefined4 *)(param_2 + 0x38) >> 0x18);
      local_10[10] = (char)*(undefined4 *)(param_2 + 0x3c);
      local_10[0xb] = (char)((uint)*(undefined4 *)(param_2 + 0x3c) >> 8);
      local_10[0xc] = (char)((uint)*(undefined4 *)(param_2 + 0x3c) >> 0x10);
      local_10[0xd] = (char)((uint)*(undefined4 *)(param_2 + 0x3c) >> 0x18);
      local_10[0xe] = (char)*(undefined4 *)(param_2 + 0x40);
      local_10[0xf] = (char)((uint)*(undefined4 *)(param_2 + 0x40) >> 8);
      local_10[0x10] = (char)((uint)*(undefined4 *)(param_2 + 0x40) >> 0x10);
      local_10[0x11] = (char)((uint)*(undefined4 *)(param_2 + 0x40) >> 0x18);
    }
    FUN_600b9408(*(undefined4 *)(param_1 + 300),0,iVar1);
  }
  return;
}


