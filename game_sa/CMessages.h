#pragma once

#define VAR_CMessages__PreviousBriefs = 0xC1A570
#define VAR_CMessages__BriefMessages = 0xC1A7F0
#define VAR_CMessages__BIGMessages = 0xC1A970
#define FUNC_CMessages__GetStringLength 0x69DB50
#define FUNC_CMessages__StringCopy 0x69DB70
#define FUNC_CMessages__StringCompare 0x69DBD0
#define FUNC_CMessages__CutString 0x69DC50
#define FUNC_CMessages__ClearMessages 0x69DCD0
#define FUNC_CMessages__ClearSmallMessagesOnly 0x69DD30
#define FUNC_CMessages__AddToPreviousBriefArray 0x69DD50
#define FUNC_CMessages__ClearPreviousBriefArray 0x69DE70
#define FUNC_CMessages__InsertNumberInString 0x69DE90
#define FUNC_CMessages__InsertStringInString 0x69E040
#define FUNC_CMessages__InsertPlayerControlKeysInString 0x69E160
#define FUNC_CMessages__AddMessageWithNumber 0x69E360
#define FUNC_CMessages__AddMessageJumpQWithNumber 0x69E4E0
#define FUNC_CMessages__AddBigMessageWithNumber 0x69E5F0
#define FUNC_CMessages__AddBigMessageWithNumberQ 0x69E6E0
#define FUNC_CMessages__AddMessageWithString 0x69E800
#define FUNC_CMessages__AddMessageJumpQWithString 0x69E950
#define FUNC_CMessages__ClearThisPrint 0x69EA30
#define FUNC_CMessages__ClearThisBigPrint 0x69EBE0
#define FUNC_CMessages__ClearThisPrintBigNow 0x69ED80
#define FUNC_CMessages__Init 0x69EDC0
#define FUNC_CMessages__ClearAllMessagesDisplayedByGame 0x69EE00
#define FUNC_CMessages__Process 0x69EE60
#define FUNC_CMessages__Display 0x69EFC0
#define FUNC_CMessages__AddMessage 0x69F0B0
#define FUNC_CMessages__AddMessageJumpQ 0x69F1E0
#define FUNC_CMessages__AddBigMessage 0x69F2B0
#define FUNC_CMessages__AddBigMessageQ 0x69F370


#pragma pack(push, 1)
struct Message
{
	char *          m_pText;
	unsigned short  m_wFlag;
	char _pad1[2];
	unsigned int    m_dwTime;
	unsigned int    m_dwStartTime;
	int             m_dwNumber[6];
	char           *m_pString;
	unsigned char   m_bPreviousBrief;
	char _pad2[3];
};

struct BigMessage
{
	Message m_Current;
	Message m_Stack[3];
};

struct PreviousBrief
{
	char * m_pText;
	int    m_dwNumber[6];
	char * m_pString;
};

class CMessages
{
public:
	// Brief messages shown in menu. Count: 20
	static PreviousBrief *PreviousBriefs;

	// Small messages. Count: 8
	static Message *BriefMessages;

	// Big messages. Count: 7 (for each text style)
	static BigMessage *BIGMessages;

	// Returns length of a string
	static unsigned int GetStringLength(char *string)
	{
		return ((unsigned int (__cdecl *)(char *))FUNC_CMessages__GetStringLength)(string);
	}

	// Copies string src to dest
	static void StringCopy(char *dest, char *src, unsigned short len)
	{
		((void (__cdecl *)(char *, char *, unsigned short))FUNC_CMessages__StringCopy)(dest, src, len);
	}

	// Compares 2 strings
	static unsigned char StringCompare(char *str1, char *str2, unsigned short len)
	{
		return ((unsigned char (__cdecl *)(char *, char *, unsigned short))FUNC_CMessages__StringCompare)(str1, str2, len);
	}

	static void CutString(int count, char *str, char **dest)
	{
		((void (__cdecl *)(int, char *, char **))FUNC_CMessages__CutString)(count, str, dest);
	}

	// Removes registered messages
	static void ClearMessages(bool flag)
	{
		((void (__cdecl *)(bool))FUNC_CMessages__ClearMessages)(flag);
	}

	// Removes small messages
	static void ClearSmallMessagesOnly()
	{
		((void (__cdecl *)())FUNC_CMessages__ClearSmallMessagesOnly)();
	}

	// Adds message to previous brief
	static void AddToPreviousBriefArray(char *text, int n1, int n2, int n3, int n4, int n5, int n6, char *string)
	{
		((void (__cdecl *)(char *, int, int, int, int, int, int, char *))FUNC_CMessages__AddToPreviousBriefArray)(text, n1, n2, n3, n4, n5, n6, string);
	}

	// Removes messages from previous brief
	static void ClearPreviousBriefArray()
	{
		((void (__cdecl *)())FUNC_CMessages__ClearPreviousBriefArray)();
	}

	// Inserts numbers into string
	static void InsertNumberInString(char *src, int n1, int n2, int n3, int n4, int n5, int n6, char *dst)
	{
		((void (__cdecl *)(char *, int, int, int, int, int, int, char *))FUNC_CMessages__InsertNumberInString)(src, n1, n2, n3, n4, n5, n6, dst);
	}

	// Inserts string into src
	static void InsertStringInString(char *src, char *string)
	{
		((void (__cdecl *)(char *, char *))FUNC_CMessages__InsertStringInString)(src, string);
	}

	// Inserts key events into string
	static void InsertPlayerControlKeysInString(char *string)
	{
		((void (__cdecl *)(char *))FUNC_CMessages__InsertPlayerControlKeysInString)(string);
	}

	// Adds message with numbers to queue
	static void AddMessageWithNumber(char *text, unsigned int time, unsigned short flag, int n1, int n2, int n3, int n4, int n5, int n6, bool bPreviousBrief)
	{
		((void (__cdecl *)(char *, unsigned int, unsigned short, int, int, int, int, int, int, bool))FUNC_CMessages__AddMessageWithNumber)(text, time, flag, n1, n2, n3, n4, n5, n6, bPreviousBrief);
	}

	// Adds message with numbers and shows it instantly
	static void AddMessageJumpQWithNumber(char *text, unsigned int time, unsigned short flag, int n1, int n2, int n3, int n4, int n5, int n6, bool bPreviousBrief)
	{
		((void (__cdecl *)(char *, unsigned int, unsigned short, int, int, int, int, int, int, bool))FUNC_CMessages__AddMessageJumpQWithNumber)(text, time, flag, n1, n2, n3, n4, n5, n6, bPreviousBrief);
	}

	// Adds big message with numbers and shows it instantly
	static void AddBigMessageWithNumber(char *text, unsigned int time, unsigned short style, int n1, int n2, int n3, int n4, int n5, int n6)
	{
		((void (__cdecl *)(char *, unsigned int, unsigned short, int, int, int, int, int, int))FUNC_CMessages__AddBigMessageWithNumber)(text, time, style, n1, n2, n3, n4, n5, n6);
	}

	// Adds big message with numbers to queue
	static void AddBigMessageWithNumberQ(char *text, unsigned int time, unsigned short style, int n1, int n2, int n3, int n4, int n5, int n6)
	{
		((void (__cdecl *)(char *, unsigned int, unsigned short, int, int, int, int, int, int))FUNC_CMessages__AddBigMessageWithNumberQ)(text, time, style, n1, n2, n3, n4, n5, n6);
	}

	// Adds message with string to queue
	static void AddMessageWithString(char *text, unsigned int time, unsigned short flag, char *string, char bPreviousBrief)
	{
		((void (__cdecl *)(char *, unsigned int, unsigned short, char *, bool))FUNC_CMessages__AddMessageWithString)(text, time, flag, string, bPreviousBrief);
	}

	// Adds message with string and shows it instantly
	static void AddMessageJumpQWithString(char *text, unsigned int time, unsigned short flag, char *string, char bPreviousBrief)
	{
		((void (__cdecl *)(char *, unsigned int, unsigned short, char *, bool))FUNC_CMessages__AddMessageJumpQWithString)(text, time, flag, string, bPreviousBrief);
	}

	// Removes small message with this text
	static void ClearThisPrint(char *text)
	{
		((void (__cdecl *)(char *))FUNC_CMessages__ClearThisPrint)(text);
	}

	// Removes big message with this text
	static void ClearThisBigPrint(char *text)
	{
		((void (__cdecl *)(char *))FUNC_CMessages__ClearThisBigPrint)(text);
	}

	// Removes first big message in messages stack
	static void ClearThisPrintBigNow(unsigned short style)
	{
		((void (__cdecl *)(unsigned short))FUNC_CMessages__ClearThisPrintBigNow)(style);
	}

	// Initialises messages
	static void Init(bool flag)
	{
		((void (__cdecl *)(bool))FUNC_CMessages__Init)(flag);
	}
	
	// Removes all displayed messages
	static void ClearAllMessagesDisplayedByGame()
	{
		((void (__cdecl *)())FUNC_CMessages__ClearAllMessagesDisplayedByGame)();
	}

	// Processing messages. This is called from CWorld::Process
	static void Process()
	{
		((void (__cdecl *)())FUNC_CMessages__Process)();
	}

	// Displays messages
	static void Display(bool flag)
	{
		((void (__cdecl *)(bool))FUNC_CMessages__Display)(flag);
	}

	// Adds message to queue
	static void AddMessage(char *text, unsigned int time, unsigned short flag, bool bPreviousBrief)
	{
		((void (__cdecl *)(char *, unsigned int, unsigned short, bool))FUNC_CMessages__AddMessage)(text, time, flag, bPreviousBrief);
	}

	// Adds message and shows it instantly
	static void AddMessageJumpQ(char *text, unsigned int time, unsigned short flag, bool bPreviousBrief)
	{
		((void (__cdecl *)(char *, unsigned int, unsigned short, bool))FUNC_CMessages__AddMessageJumpQ)(text, time, flag, bPreviousBrief);
	}

	// Adds big message and shows it instantly
	static void AddBigMessage(char *text, unsigned int time, unsigned short style)
	{
		((void (__cdecl *)(char *, unsigned int, unsigned short))FUNC_CMessages__AddBigMessage)(text, time, style);
	}

	// Adds big message to queue
	static void AddBigMessageQ(char *text, unsigned int time, unsigned short style)
	{
		((void (__cdecl *)(char *, unsigned int, unsigned short))FUNC_CMessages__AddBigMessageQ)(text, time, style);
	}

};
#pragma pack(pop)