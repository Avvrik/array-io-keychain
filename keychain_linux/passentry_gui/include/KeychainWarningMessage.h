#ifndef KEYCHAINWARNINGMESSAGE_H
#define KEYCHAINWARNINGMESSAGE_H

#include <QString>
#include <QStack>

class KeychainWarningMessage {
public:
	enum WarningType {
		NoWarnig = 0,
		CreateWarning = 1,
		UnlockWarning = 2,
		UnlockUseWarning = 3,
		HashWarnig =4,
		FailedWarning = 5,
		HexWarning = 6
	};

public:
	KeychainWarningMessage() {
		_warnTypes = new QStack<int>();
		_messages[0] = "This transaction is successfully parsed by the core module. No threats detected. You can now review the transaction details.";
		_messages[1] = "Your private key is encrypted and secure.";
		_messages[2] = "Experimental function 'unlock key' will be activated once you enter the passphrase. During this time operations with the unlocked key will be executed without user confirmation.";
		_messages[3] = "Experimental function 'unlock key' has been activated. During this time KeyChain will be able to sign transactions without user confirmation.";
		_messages[4] = "Using transaction hash does not provide any information about the transaction. Use the transaction hash only if you trust the app requesting the signature.";
		_messages[5] = "KeyChain can provide only hex view of the transaction without additional information, such as address, amount, and any other additional information. Confim the transaction only if you trust the app requesting the signature.";
		_messages[6] = "KeyChain can provide only hex view of the transaction without additional information, such as address, amount, and any other detail. Confim the transaction only if you trust the app requesting the signature.";
		
	}

	void SetWarning(WarningType warning) {
		_warnTypes->push((int)warning);
		if (warning >= 2) {
			_isWarn = true;
		}
		//_warnType = warning;
	}

	QString GetMessage() const {
		QString _message("");
		bool isFirst = true;
		while (!_warnTypes->isEmpty()) {
			if (isFirst == false) {
				_message += '\n';
				_message += '\n';
			}
			int _mIndex = (int)_warnTypes->pop();
			_message += _messages[_mIndex];
			if (isFirst)
				isFirst = false;
		}
		return _message;
	}

	int MessgeCount() const {
		return _warnTypes->length();
	}

	bool isWarn() const {
		return _isWarn;
	}

private:
	QString _messages[7];
	QStack<int> * _warnTypes;
	bool _isWarn = false;
};

#endif