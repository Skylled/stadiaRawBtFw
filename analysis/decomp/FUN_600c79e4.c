// 600c79e4  FUN_600c79e4  size=194 bytes
// --- callers ---
//   600ffada FUN_600ffada
// --- callees ---
//   6006dbac FUN_6006dbac
//   600f69f0 FUN_600f69f0


int FUN_600c79e4(undefined1 param_1,undefined2 param_2,undefined2 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  short sVar1;
  int local_20;
  int local_1c;
  
  local_1c = 0;
  local_1c = FUN_6006dbac(0x1d,DAT_600c7aa8,0x83);
  if (local_1c != 0) {
    *(undefined2 *)(local_1c + 4) = 0xd;
    *(undefined2 *)(local_1c + 2) = 5;
    *(undefined1 *)(local_1c + 0x15) = param_1;
    *(char *)(local_1c + 0x16) = (char)param_2;
    *(char *)(local_1c + 0x17) = (char)((ushort)param_2 >> 8);
    *(char *)(local_1c + 0x18) = (char)param_3;
    local_20 = local_1c + 0x1a;
    *(char *)(local_1c + 0x19) = (char)((ushort)param_3 >> 8);
    sVar1 = FUN_600f69f0(&local_20,param_4,param_5,param_6,param_7,param_8);
    *(short *)(local_1c + 2) = sVar1 + *(short *)(local_1c + 2);
  }
  return local_1c;
}


